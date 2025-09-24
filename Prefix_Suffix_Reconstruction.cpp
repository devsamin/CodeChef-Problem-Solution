#include <bits/stdc++.h>
using namespace std;

void samin_solved() {
    int T; 
    if (!(cin >> T)) return;

    while (T--) {
        int N;
        long long K;
        cin >> N >> K;

        vector<int> parent(N + 1);
        vector<long long> coef(N + 1, 1);
        vector<vector<int>> tree(N + 1);

        for (int i = 2; i <= N; i++) {
            cin >> parent[i];
            tree[parent[i]].push_back(i);
        }
        for (int i = 2; i <= N; i++) cin >> coef[i];

        // পানির পরিমাণ হিসাব করা
        vector<long long> flow(N + 1, 0);
        flow[1] = K;
        for (int i = 2; i <= N; i++) {
            long long fromPar = flow[parent[i]];
            flow[i] = fromPar - fromPar / coef[i];
        }

        const long long INF = (1LL << 62);
        vector<long long> minDown(N + 1, INF), minUp(N + 1, INF);

        // সাবট্রি মিনিমাম
        for (int i = N; i >= 1; i--) {
            if (tree[i].empty()) minDown[i] = flow[i];
            else {
                long long best = INF;
                for (int c : tree[i]) best = min(best, minDown[c]);
                minDown[i] = best;
            }
        }

        // উপরের দিকের মিনিমাম
        minUp[1] = INF;
        vector<int> bfs = {1};
        for (size_t qi = 0; qi < bfs.size(); qi++) {
            int u = bfs[qi];
            int m = tree[u].size();
            vector<long long> pre(m + 1, INF), suf(m + 1, INF);
            for (int i = 0; i < m; i++) pre[i + 1] = min(pre[i], minDown[tree[u][i]]);
            for (int i = m - 1; i >= 0; i--) suf[i] = min(suf[i + 1], minDown[tree[u][i]]);
            for (int i = 0; i < m; i++) {
                int v = tree[u][i];
                long long excl = min(pre[i], suf[i + 1]);
                minUp[v] = min(minUp[u], excl);
                bfs.push_back(v);
            }
        }

        // feasibility চেক
        auto canReach = [&](long long target)->bool {
            if (minDown[1] >= target) return true;
            vector<long long> need(N + 1, 0);
            for (int v = N; v >= 1; v--) {
                if (tree[v].empty()) need[v] = target;
                else {
                    long long req = 0;
                    for (int c : tree[v]) {
                        long long needChild = need[c];
                        long long val = 0;
                        if (needChild > 0) {
                            if (coef[c] == 1) return false;
                            long long q = (needChild + coef[c] - 2) / (coef[c] - 1);
                            val = min(needChild + q - 1, q * coef[c]);
                        }
                        req = max(req, val);
                    }
                    need[v] = req;
                }
            }
            for (int v = 2; v <= N; v++) {
                if (minUp[v] >= target && flow[parent[v]] >= need[v]) 
                    return true;
            }
            return false;
        };

        // binary search
        long long lo = 0, hi = K, ans = 0;
        while (lo <= hi) {
            long long mid = (lo + hi) >> 1;
            if (canReach(mid)) { ans = mid; lo = mid + 1; }
            else hi = mid - 1;
        }
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    samin_solved();
    return 0;
}
