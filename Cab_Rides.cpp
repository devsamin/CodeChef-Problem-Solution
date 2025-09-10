#include <bits/stdc++.h>
using namespace std;

int solved_samin(int total_items) {
    int full_sets = total_items / 4;
    int remainder = total_items % 4;
    int total_cost = 0;

    if (remainder == 0) {
        total_cost = full_sets * 400;
    } else if (remainder == 1) {
        if (full_sets >= 1) {
            total_cost = (full_sets - 1) * 400 + 300 + 200;
        } else {
            total_cost = 200;  // case when total_items == 1
        }
    } else if (remainder == 2) {
        total_cost = full_sets * 400 + 200;
    } else { 
        total_cost = full_sets * 400 + 300;  // remainder == 3
    }

    return total_cost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int total_tests;
    if (!(cin >> total_tests)) return 0;

    while (total_tests--) {
        int input_number;
        cin >> input_number;
        cout << solved_samin(input_number) << '\n';
    }

    return 0;
}
