#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

// contribution of a single cycle length
ll cycle_contribution(int cycle_len, int perm_size) {
    ll sum = 0;
    for (int val = 1; val <= perm_size; val++) {
        ll t = (ll)cycle_len * val + (cycle_len - 2);
        ll k = t / (cycle_len - 1) - 1;
        k = max(0LL, min((ll)perm_size, k));

        ll preSum = (cycle_len - 1) * k * (k + 1) / 2;
        ll postSum = (perm_size - k) * (ll)cycle_len * val;

        sum = (sum + preSum + postSum) % MOD;
    }
    return sum;
}

// main function
ll solved_samin(const vector<int>& perm) {
    int n = perm.size() - 1; // 1-based indexing
    vector<bool> seen(n + 1, false);
    unordered_map<int,int> cycleFreq;

    for (int idx = 1; idx <= n; idx++) {
        if (!seen[idx]) {
            int curr = idx, len = 0;
            while (!seen[curr]) {
                seen[curr] = true;
                len++;
                curr = perm[curr];
            }
            if (len >= 2) cycleFreq[len]++;
        }
    }

    ll total = 0;
    for (auto &entry : cycleFreq) {
        int cLen = entry.first;
        int f = entry.second;
        total = (total + f * cycle_contribution(cLen, n) % MOD) % MOD;
    }
    return total;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int sz;
        cin >> sz;
        vector<int> perm(sz + 1);
        for (int i = 1; i <= sz; i++) cin >> perm[i];

        cout << solved_samin(perm) << "\n";
    }

    return 0;
}
