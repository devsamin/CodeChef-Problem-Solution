#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

void samin_solved() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int totalCases; 
    if (!(cin >> totalCases)) return;

    while (totalCases--) {
        int totalNums, modValue;
        cin >> totalNums >> modValue;

        vector<int> values(totalNums);
        int64 initialSum = 0;

        for (int i = 0; i < totalNums; i++) {
            cin >> values[i];
            initialSum += values[i];
        }

        // frequency of each remainder
        vector<int> remainderFreq(modValue + 1, 0);
        for (int val : values) {
            remainderFreq[val]++;
        }

        // suffix count: how many numbers >= threshold
        vector<int> suffixCount(modValue + 2, 0);
        for (int threshold = modValue; threshold >= 0; threshold--) {
            suffixCount[threshold] = suffixCount[threshold + 1] + remainderFreq[threshold];
        }

        int64 bestAdjustment = LLONG_MAX;

        for (int threshold = 1; threshold <= modValue; threshold++) {
            int countLarge = suffixCount[threshold];  
            int64 shiftVal = (int64)modValue - threshold; 
            int64 currentAdjustment = (int64)totalNums * shiftVal - (int64)modValue * countLarge;
            bestAdjustment = min(bestAdjustment, currentAdjustment);
        }

        int64 finalAnswer = initialSum + bestAdjustment;
        cout << finalAnswer << "\n";
    }
}

int main() {
    samin_solved();
    return 0;
}
