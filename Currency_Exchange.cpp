#include <bits/stdc++.h>
using namespace std;

void samin_solve() {
    int A1, B1, A2, B2;
    cin >> A1 >> B1 >> A2 >> B2;

    if (A1 == A2 && B1 == B2) {
        cout << "Yes\n";
        return;
    }
    int diff = (A1 + B1) - (A2 + B2);
    if (diff % 2 != 0) {
        cout << "No\n";
        return;
    }

    if (A2 > A1) {
        int need_silver = (A2 - A1) * 5;
        if (B1 < need_silver) {
            cout << "No\n";
            return;
        }
    }

    if (B2 > B1) {
        int silver_needed = B2 - B1;
        int gold_required = (silver_needed + 4) / 5; // ceiling
        if (A1 < gold_required) {
            cout << "No\n";
            return;
        }
    }

    cout << "Yes\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        samin_solve();
    }
    return 0;
}
