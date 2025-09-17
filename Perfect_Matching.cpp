 #include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353LL;

ll mod_pow(ll a, ll b, ll m) {
    ll res = 1;
    a %= m;
    while (b) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    const int MAX = 10000;
    vector<ll> fact(MAX + 1, 1);
    for (int i = 1; i <= MAX; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }
    vector<ll> invfact(MAX + 1);
    invfact[MAX] = mod_pow(fact[MAX], MOD - 2, MOD);
    for (int i = MAX - 1; i >= 0; i--) {
        invfact[i] = invfact[i + 1] * (i + 1) % MOD;
    }
    vector<ll> invv(MAX + 1, 0);
    for (int i = 1; i <= MAX; i++) {
        invv[i] = invfact[i] * fact[i - 1] % MOD;
    }
    vector<ll> AA(MAX + 1, 0), BB(MAX + 1, 0);
    vector<ll> ee(MAX + 1, 0);
    ee[0] = 1;
    BB[1] = 1;
    for (int m = 2; m <= MAX; m++) {
        ll tempsum = 0;
        if (m % 2 == 0) {
            for (int l = 1; l < m; l += 2) {
                int deg = m - 1 - l;
                if (deg < 0) continue;
                ll term = BB[l] * invfact[l] % MOD * ee[deg] % MOD;
                tempsum = (tempsum + term) % MOD;
            }
            AA[m] = fact[m - 1] * tempsum % MOD;
        } else {
            int deg = m - 1;
            if (deg <= MAX) {
                BB[m] = fact[deg] * ee[deg] % MOD;
            }
        }
        if (m % 2 == 0) {
            ll delta = AA[m] * invfact[m] % MOD;
            int Kmax = MAX / m;
            vector<ll> coef(Kmax + 1, 0);
            coef[0] = 1;
            ll powd = 1;
            ll ifkk = 1;
            for (int k = 1; k <= Kmax; k++) {
                powd = powd * delta % MOD;
                ifkk = ifkk * invv[k] % MOD;
                coef[k] = powd * ifkk % MOD;
            }
            vector<ll> newee(MAX + 1, 0);
            for (int k = 0; k <= Kmax; k++) {
                ll c = coef[k];
                if (c == 0) continue;
                int shift = k * m;
                for (int jj = 0; jj <= MAX - shift; jj++) {
                    int j = jj + shift;
                    newee[j] = (newee[j] + c * ee[jj] % MOD) % MOD;
                }
            }
            ee = newee;
        }
    }
    vector<ll> ans(MAX + 1, 0);
    for (int n = 1; n <= MAX; n++) {
        if (n % 2 == 1) {
            ans[n] = 0;
        } else {
            ans[n] = AA[n] * invfact[n - 1] % MOD;
        }
    }
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;
        cout << ans[N] << '\n';
    }
    return 0;
}
