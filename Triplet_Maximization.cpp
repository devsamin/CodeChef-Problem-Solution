#include <bits/stdc++.h>
using namespace std;

void samin_solved() {
    int T;
    cin >> T;
    while (T--) {
        int X, Y;
        cin >> X >> Y;

        int groups = (X + Y) / 3;              // মোট ট্রিপল সংখ্যা
        int twosUsed = min(Y, groups);         // কতগুলো ট্রিপলে 2 বসানো যাবে
        int ans = groups + twosUsed;           // ফর্মুলা: groups + min(Y, groups)

        cout << ans << "\n";
    }
}

int main() {
    samin_solved();
    return 0;
}
