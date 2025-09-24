#include <bits/stdc++.h>
using namespace std;

void samin_solved() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        if (K == N) {
            cout << 0 << "\n";
            continue;
        }

        // Option 1: move directly to N
        int direct = N - K;

        // Option 2: mirror once, then move
        int mirrorPos = N + 1 - K;
        int viaMirror = 1 + abs(N - mirrorPos);

        cout << min(direct, viaMirror) << "\n";
    }
}

int main() {
    samin_solved();
    return 0;
}
