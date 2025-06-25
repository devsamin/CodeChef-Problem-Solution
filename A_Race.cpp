#include <iostream>
#include <cmath> // For abs()

using namespace std;

int main() {
    int t;
    cin >> t; // Number of test cases

    while (t--) {
        int a, x, y;
        cin >> a >> x >> y; // Input a, x, y

        int alice_x = abs(a - x); // Alice's distance to x
        int alice_y = abs(a - y); // Alice's distance to y
        bool found = false; // To check if any valid b exists

        for (int b = 1; b <= 100; ++b) {
            if (b == a) continue; // Bob can't start at same point as Alice

            if (abs(b - x) < alice_x && abs(b - y) < alice_y) {
                found = true;
                break;
            }
        }

        if (found) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
