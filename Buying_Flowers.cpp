#include <bits/stdc++.h>
using namespace std;

void solved_samin() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int totalTests;
    cin >> totalTests;

    while (totalTests--) {
        int totalSteps;
        cin >> totalSteps;

        vector<long long> minCost(totalSteps + 1, LLONG_MAX);
        minCost[0] = 0;

        for (int stepIndex = 2; stepIndex <= totalSteps; ++stepIndex) {
            if (stepIndex >= 2 && minCost[stepIndex - 2] != LLONG_MAX) {
                minCost[stepIndex] = min(minCost[stepIndex], minCost[stepIndex - 2] + 4);
            }
            if (stepIndex >= 3 && minCost[stepIndex - 3] != LLONG_MAX) {
                minCost[stepIndex] = min(minCost[stepIndex], minCost[stepIndex - 3] + 5);
            }
        }

        cout << minCost[totalSteps] << '\n';
    }
}

int main() {
    solved_samin();
    return 0;
}
