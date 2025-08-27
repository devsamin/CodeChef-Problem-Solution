#include <bits/stdc++.h>
using namespace std;

string solved_samin(int countA, int countB) {
    string pattern;

    if (countA >= 1 && countB >= 1) {
        // '<' repeated 2 * countA times
        pattern += string(2 * countA, '<');
        // '><' repeated (countB-1) times
        for (int i = 0; i < countB - 1; i++) pattern += "><";
        pattern += '>';
    }
    else if (countB == 0) { // only countA >= 1
        pattern += string(2 * countA - 3, '<');
        pattern += '=';
        pattern += '<';
    }
    else { // countA == 0 && countB >= 2
        for (int i = 0; i < countB - 2; i++) pattern += "><";
        pattern += ">=>";
    }

    return pattern;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCaseCount;
    cin >> testCaseCount;

    while (testCaseCount--) {
        int numN, numM;
        cin >> numN >> numM;

        cout << solved_samin(numN, numM) << "\n";
    }

    return 0;
}
