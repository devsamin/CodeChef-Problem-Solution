#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

void samin_solved() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int samin_tests;
    if (!(cin >> samin_tests)) return;

    while (samin_tests--) {
        int samin_n;
        int64 samin_k;
        cin >> samin_n >> samin_k;

        vector<int64> samin_height(samin_n);
        for (int i = 0; i < samin_n; ++i) cin >> samin_height[i];

        // Step 1: Calculate initial perimeter
        int64 samin_perimeter = 2LL * samin_n;
        samin_perimeter += samin_height[0] + samin_height[samin_n - 1];
        for (int i = 0; i + 1 < samin_n; ++i) {
            samin_perimeter += llabs(samin_height[i + 1] - samin_height[i]);
        }

        if (samin_perimeter <= samin_k) {
            cout << 0 << '\n';
            continue;
        }

        // Step 2: Layers needed (each layer reduces perimeter by 2)
        int64 samin_extra = samin_perimeter - samin_k;
        int64 samin_need = (samin_extra + 1) / 2; // ceil division

        // Step 3: Count available unit-layers by interior width
        vector<int64> samin_count(samin_n + 1, 0);
        vector<int> samin_stack;
        samin_stack.reserve(samin_n);

        for (int i = 0; i < samin_n; ++i) {
            while (!samin_stack.empty() && samin_height[samin_stack.back()] <= samin_height[i]) {
                int samin_mid = samin_stack.back();
                samin_stack.pop_back();
                if (samin_stack.empty()) break;

                int samin_left = samin_stack.back();
                int samin_right = i;
                int samin_width = samin_right - samin_left - 1;
                if (samin_width <= 0) continue;

                int64 samin_h = min(samin_height[samin_left], samin_height[samin_right]) - samin_height[samin_mid];
                if (samin_h > 0) samin_count[samin_width] += samin_h;
            }
            samin_stack.push_back(i);
        }

        // Step 4: Check if enough layers exist
        int64 samin_total_layers = 0;
        for (int w = 1; w <= samin_n; ++w) samin_total_layers += samin_count[w];

        if (samin_total_layers < samin_need) {
            cout << -1 << '\n';
            continue;
        }

        // Step 5: Greedy pick from smallest width
        long long samin_ops = 0;
        int64 samin_left_need = samin_need;

        for (int w = 1; w <= samin_n && samin_left_need > 0; ++w) {
            if (samin_count[w] == 0) continue;
            int64 take = min(samin_count[w], samin_left_need);
            samin_ops += take * 1LL * w;
            samin_left_need -= take;
        }

        cout << samin_ops << '\n';
    }
}

int main() {
    samin_solved();
    return 0;
}
