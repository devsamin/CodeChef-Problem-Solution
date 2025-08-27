#include <bits/stdc++.h>
using namespace std;

int solved_samin(int length, const string &binary_str) {
    int total_ones = 0;
    for (char ch : binary_str) if (ch == '1') total_ones++;

    int first_one = (binary_str.front() == '1') ? 1 : 0;
    int last_one = (binary_str.back() == '1') ? 1 : 0;

    return 3 * total_ones - (first_one + last_one);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        int n;
        string s;
        cin >> n >> s;
        cout << solved_samin(n, s) << "\n";
    }
    return 0;
}
