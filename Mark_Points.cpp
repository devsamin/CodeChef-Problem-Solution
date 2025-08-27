#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        string s;
        cin >> n >> s;

        // মোট কয়টা '1' আছে
        int ones = count(s.begin(), s.end(), '1');

        // প্রথম ক্যারেক্টার
        int a1 = (s[0] == '1') ? 1 : 0;
        // শেষ ক্যারেক্টার
        int an = (s[n - 1] == '1') ? 1 : 0;

        int ans = 3 * ones - (a1 + an);

        cout << ans << "\n";
    }
    return 0;
}
