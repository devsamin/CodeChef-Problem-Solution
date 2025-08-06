#include <bits/stdc++.h>
using namespace std;

void solved_samin() {
    int n;
    cin >> n;

    priority_queue<int> left_half;
    priority_queue<int, vector<int>, greater<int>> right_half;

    vector<int> medians;

    for (int i = 0; i < n; i++) {
        int a_val;
        cin >> a_val;
        int b_val = abs(a_val) % 10;

        if (left_half.empty() || b_val <= left_half.top()) {
            left_half.push(b_val);
        } else {
            right_half.push(b_val);
        }

        if (left_half.size() > right_half.size() + 1) {
            right_half.push(left_half.top());
            left_half.pop();
        } else if (right_half.size() > left_half.size()) {
            left_half.push(right_half.top());
            right_half.pop();
        }
        
        medians.push_back(left_half.top());
    }

    for (int i = 0; i < medians.size(); i++) {
        cout << medians[i] << (i == medians.size() - 1 ? "" : " ");
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solved_samin();
    }

    return 0;
}