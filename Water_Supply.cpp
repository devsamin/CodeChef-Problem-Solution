#include <bits/stdc++.h>
using namespace std;

void samin_solved() {
    int tcase;
    if (!(cin >> tcase)) return;

    while (tcase--) {
        int nodes;
        long long initWater;
        cin >> nodes >> initWater;

        vector<int> parent(nodes + 1, 0);
        vector<long long> coef(nodes + 1, 1);
        vector<vector<int>> graph(nodes + 1);

        for (int i = 2; i <= nodes; i++) {
            cin >> parent[i];
            graph[parent[i]].push_back(i);
        }
        for (int i = 2; i <= nodes; i++) cin >> coef[i];

        vector<long long> flow(nodes + 1, 0);
        flow[1] = initWater;
        for (int i = 2; i <= nodes; i++) {
            long long parFlow = flow[parent[i]];
            flow[i] = parFlow - parFlow / coef[i];
        }

        const long long INFLL = (1LL << 62);
        vector<long long> minDown(nodes + 1, INFLL), minUp(nodes + 1, INFLL);

        for (int v = nodes; v >= 1; v--) {
            if (graph[v].empty()) minDown[v] = flow[v];
            else {
                long long best = INFLL;
                for (int nxt : graph[v]) best = min(best, minDown[nxt]);
                minDown[v] = best;
            }
        }

        minUp[1] = INFLL;
        vector<int> bfs;
        bfs.reserve(nodes);
        bfs.push_back(1);

        for (size_t qi = 0; qi < bfs.size(); qi++) {
            int u = bfs[qi];
            int m = (int)graph[u].size();
            vector<long long> pref(m + 1, INFLL), suff(m + 1, INFLL);

            for (int i = 0; i < m; i++) pref[i + 1] = min(pref[i], minDown[graph[u][i]]);
            for (int i = m - 1; i >= 0; i--) suff[i] = min(suff[i + 1], minDown[graph[u][i]]);

            for (int i = 0; i < m; i++) {
                int v = graph[u][i];
                long long excl = min(pref[i], suff[i + 1]);
                minUp[v] = min(minUp[u], excl);
                bfs.push_back(v);
            }
        }

        auto okCheck = [&](long long target)->bool {
            if (minDown[1] >= target) return true;

            vector<long long> need(nodes + 1, 0);
            long long cap = initWater;

            for (int v = nodes; v >= 1; v--) {
                if (graph[v].empty()) need[v] = target;
                else {
                    long long reqVal = 0;
                    for (int c : graph[v]) {
                        long long needChild = need[c], tmp = 0;
                        if (needChild == 0) tmp = 0;
                        else if (needChild > cap) { reqVal = cap + 1; break; }
                        else {
                            long long coeff = coef[c];
                            if (coeff == 1) { reqVal = cap + 1; break; }
                            long long q0 = (needChild + (coeff - 2)) / (coeff - 1);
                            long long val1 = needChild + q0 - 1;
                            if (val1 > cap + 1) val1 = cap + 1;
                            long long val2;
                            if (q0 > (cap + 1) / coeff) val2 = cap + 1;
                            else val2 = q0 * coeff;
                            tmp = min(val1, val2);
                            if (tmp > cap) tmp = cap + 1;
                        }
                        if (tmp > reqVal) reqVal = tmp;
                        if (reqVal > cap) break;
                    }
                    need[v] = reqVal;
                }
            }

            for (int v = 2; v <= nodes; v++) {
                if (minUp[v] >= target) {
                    if (flow[parent[v]] >= need[v]) return true;
                }
            }
            return false;
        };

        long long lo = 0, hi = initWater, bestAns = 0;
        while (lo <= hi) {
            long long mid = (lo + hi) >> 1;
            if (okCheck(mid)) { bestAns = mid; lo = mid + 1; }
            else hi = mid - 1;
        }
        cout << bestAns << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    samin_solved();
    return 0;
}
