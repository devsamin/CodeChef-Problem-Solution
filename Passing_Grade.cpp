#include <bits/stdc++.h>
using namespace std;

int samin_solved(vector<int>& score_list) {
    int chef_score = score_list[0];
    int greater_equal_count = 0;
    for (int value : score_list) {
        if (value >= chef_score) ++greater_equal_count;
    }
    return greater_equal_count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int total_tests;
    if (!(cin >> total_tests)) return 0;

    while (total_tests--) {
        int num_players;
        cin >> num_players;

        vector<int> performance_list(num_players);
        for (int i = 0; i < num_players; ++i) {
            cin >> performance_list[i];
        }

        cout << samin_solved(performance_list) << '\n';
    }

    return 0;
}
