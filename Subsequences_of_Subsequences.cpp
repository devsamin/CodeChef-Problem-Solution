#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int add_to_basis(vector<unsigned int>& xor_basis, unsigned int candidate) {
    int basis_size = (int)xor_basis.size();
    for (int pos = basis_size - 1; pos >= 0; --pos) {
        if (!(candidate & (1u << pos))) continue;
        if (!xor_basis[pos]) {
            xor_basis[pos] = candidate;
            return 1; // inserted successfully
        }
        candidate ^= xor_basis[pos];
    }
    return 0; // already dependent
}

ll solved_samin(int element_count, int group_size, vector<unsigned int>& data_array) {
    unsigned int cumulative_xor = 0;
    for (auto val : data_array) {
        cumulative_xor ^= val;
    }

    // compute xor-basis rank
    vector<unsigned int> xor_basis_30(30, 0);
    int rank_value = 0;
    for (auto val : data_array) {
        rank_value += add_to_basis(xor_basis_30, val);
    }

    if (group_size == element_count) {
        return (cumulative_xor == 0 ? 1 : 2);
    }

    if (group_size % 2 == 1) {
        return 1LL << rank_value;
    }

    // even group_size and group_size <= element_count - 1
    vector<unsigned int> xor_basis_31(31, 0);
    int rank_augmented = 0;
    for (auto val : data_array) {
        unsigned int shifted_val = (val << 1) | 1u;
        rank_augmented += add_to_basis(xor_basis_31, shifted_val);
    }

    int effective_rank;
    if (rank_augmented == rank_value + 1) {
        effective_rank = rank_value;
    } else {
        effective_rank = max(0, rank_value - 1);
    }

    return 1LL << effective_rank;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int total_tests;
    if (!(cin >> total_tests)) return 0;

    while (total_tests--) {
        int input_n, input_k;
        cin >> input_n >> input_k;
        vector<unsigned int> input_array(input_n);
        for (int i = 0; i < input_n; i++) {
            cin >> input_array[i];
        }
        cout << solved_samin(input_n, input_k, input_array) << '\n';
    }

    return 0;
}
