#include <bits/stdc++.h>
using namespace std;

void solved_samin() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int totalTests;
    cin >> totalTests;

    while (totalTests--) {
        int arraySize, dummyQuery;
        cin >> arraySize >> dummyQuery;

        vector<long long> numberList(arraySize + 1);
        for (int idx = 1; idx <= arraySize; ++idx) {
            cin >> numberList[idx];
        }

        long long finalValue = numberList[1];

        for (int pos = 2; pos <= arraySize; ++pos) {
            if (pos % 2 == 0) {
                finalValue = max(finalValue, numberList[pos]);
            } else {
                finalValue = min(finalValue, numberList[pos]);
            }
        }

        cout << finalValue << '\n';
    }
}

int main() {
    solved_samin();
    return 0;
}
