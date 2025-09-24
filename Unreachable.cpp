#include <bits/stdc++.h>
using namespace std;

void samin_solved() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tCases;
    if (!(cin >> tCases)) return;

    while (tCases--) {
        int length;
        cin >> length;

        bool oneOddPos = false, oneEvenPos = false;

        for (int pos = 1; pos <= length; pos++) {
            int val;
            cin >> val;
            if (val == 1) {
                if (pos % 2 == 1) oneOddPos = true;
                else oneEvenPos = true;
            }
        }

        if (oneOddPos && oneEvenPos) {
            cout << "No\n";
        } else {
            cout << "Yes\n";
        }
    }
}

int main() {
    samin_solved();
    return 0;
}
