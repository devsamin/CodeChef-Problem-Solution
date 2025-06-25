#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t; // number of test cases

    while (t--) {
        int x;
        cin >> x;

        // Count number of bits required to represent x (position of highest bit)
        int highest_bit = 0;
        int temp = x;
        while (temp > 0) {
            temp /= 2;
            highest_bit++;
        }

        // Count number of 1s in binary representation
        int ones = __builtin_popcount(x);

        // Final answer: highest bit + (number of ones - 1)
        int answer = highest_bit + (ones - 1);
        cout << answer << endl;
    }

    return 0;
}
