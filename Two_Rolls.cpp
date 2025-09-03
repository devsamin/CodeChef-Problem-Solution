#include <bits/stdc++.h>
using namespace std;

void solved_samin() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int totalCases;
    cin >> totalCases;

    vector<string> finalOutput;
    finalOutput.reserve(totalCases);

    for (int caseIndex = 0; caseIndex < totalCases; ++caseIndex) {
        int inputX, inputY;
        cin >> inputX >> inputY;

        int spareValue = 50 - inputX;

        if (2 * inputY <= spareValue && spareValue <= 2 * inputY + 10) {
            finalOutput.push_back("Yes");
        } else {
            finalOutput.push_back("No");
        }
    }

    for (const string &resultText : finalOutput) {
        cout << resultText << '\n';
    }
}

int main() {
    solved_samin();
    return 0;
}
