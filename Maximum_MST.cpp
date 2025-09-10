#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll samin_solved(int node_total, vector<ll>& edge_weights) {
    int total_pairs = node_total * (node_total - 1) / 2;
    sort(edge_weights.begin(), edge_weights.end()); // ascending order

    // prefix_capacity[idx] = minimal value for prefix length idx
    vector<int> prefix_capacity(total_pairs + 1, 0);
    prefix_capacity[0] = 0;

    for (int idx = 1; idx <= total_pairs; idx++) {
        // smallest group_size such that group_size*(group_size-1)/2 >= idx
        double root_calc = sqrt(1.0 + 8.0 * idx);
        int group_size = (int)ceil((1.0 + root_calc) / 2.0);
        prefix_capacity[idx] = min(node_total - 1, group_size - 1);
    }

    int edges_needed = node_total - 1;
    ll total_cost = 0;

    for (int idx = total_pairs; idx >= 1 && edges_needed > 0; --idx) {
        if (prefix_capacity[idx - 1] < edges_needed) {
            total_cost += edge_weights[idx - 1];
            --edges_needed;
        }
    }

    return total_cost;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_cases;
    if (!(cin >> test_cases)) return 0;

    while (test_cases--) {
        int vertices;
        cin >> vertices;

        int pair_count = vertices * (vertices - 1) / 2;
        vector<ll> input_weights(pair_count);

        for (int i = 0; i < pair_count; i++) {
            cin >> input_weights[i];
        }

        cout << samin_solved(vertices, input_weights) << '\n';
    }

    return 0;
}
