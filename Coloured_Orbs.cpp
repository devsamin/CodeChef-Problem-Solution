#include <bits/stdc++.h>
using namespace std;

long long samin_solved(long long red_count, long long blue_count) {
    long long smaller_val = min(red_count, blue_count);
    long long final_answer = red_count + 2 * blue_count + 2 * smaller_val;
    return final_answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long input_red, input_blue;
    if (!(cin >> input_red >> input_blue)) return 0;

    cout << samin_solved(input_red, input_blue) << '\n';
    return 0;
}
