#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if(!(cin >> T)) return 0;
    while(T--){
        int N;
        cin >> N;
        int M = N * (N - 1) / 2;
        vector<ll> w(M);
        for(int i=0;i<M;i++) cin >> w[i];
        sort(w.begin(), w.end()); // ascending

        // cap[k] for prefix of length k (0..M)
        vector<int> cap(M+1,0);
        cap[0] = 0;
        for(int k=1;k<=M;k++){
            // minimal s such that s*(s-1)/2 >= k
            // s = ceil((1 + sqrt(1 + 8k)) / 2)
            double t = sqrt(1.0 + 8.0 * k);
            int s = (int)ceil((1.0 + t) / 2.0);
            cap[k] = min(N-1, s - 1);
        }

        int need = N - 1;
        ll ans = 0;
        for(int k = M; k >= 1 && need > 0; --k){
            if(cap[k-1] < need){
                // we must take w[k-1]
                ans += w[k-1];
                --need;
            }
            // otherwise we can skip this weight
        }
        cout << ans << '\n';
    }
    return 0;
}
