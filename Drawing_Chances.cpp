#include <bits/stdc++.h>
using namespace std;

void samin_solved() {
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        string S;
        cin >> S;

        int alice = 0, bob = 0;
        for (char c : S) {
            if (c == '1') alice++;
            else bob++;
        }

        int remaining = N - M;

        // To have a tie: finalAlice == finalBob
        // => alice + extraAlice == bob + extraBob
        // => (alice - bob) == (extraBob - extraAlice)
        // Difference between Alice and Bob's current wins:
        int diff = abs(alice - bob);

        if (diff <= remaining && (remaining - diff) % 2 == 0) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    samin_solved();
    return 0;
}
