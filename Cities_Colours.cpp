#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int64 NEG_LIMIT = (int64)-9e18;

void samin_solved() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int testCases;
    if (!(cin >> testCases)) return;

    while (testCases--) {
        int numCities; 
        int64 penaltyCost;
        cin >> numCities >> penaltyCost;

        vector<int64> cityWeight(numCities + 1);
        for (int i = 1; i <= numCities; i++) cin >> cityWeight[i];

        vector<int> cityColor(numCities + 1);
        for (int i = 1; i <= numCities; i++) cin >> cityColor[i];

        // colorValue[color] = stored best value for that color (shifted by globalLazy)
        unordered_map<int, int64> colorValue;
        colorValue.reserve(numCities * 2);
        colorValue.max_load_factor(0.7);

        int64 globalLazy = 0;   // global additive lazy value
        colorValue[cityColor[1]] = 0;  // starting city
        int64 bestStored = 0;   // max of stored values (colorValue[color])

        for (int idx = 2; idx <= numCities; idx++) {
            // current best real value = bestStored + globalLazy
            int64 bestReal = bestStored + globalLazy;

            // candidate if switching to this color
            int64 switchCandidate = bestReal - penaltyCost + cityWeight[idx];

            // lazy decrease for all colors
            globalLazy -= cityWeight[idx];

            // make sure color entry exists
            if (colorValue.find(cityColor[idx]) == colorValue.end()) {
                colorValue[cityColor[idx]] = NEG_LIMIT;
            }

            // correct non-switching for this color (+2*weight because we applied -weight lazily)
            colorValue[cityColor[idx]] += 2LL * cityWeight[idx];

            // convert switching candidate to stored form
            int64 candidateStored = switchCandidate - globalLazy;

            // update the stored value for this color
            if (candidateStored > colorValue[cityColor[idx]]) {
                colorValue[cityColor[idx]] = candidateStored;
            }

            // update bestStored
            if (colorValue[cityColor[idx]] > bestStored) {
                bestStored = colorValue[cityColor[idx]];
            }
        }

        int64 finalAnswer = bestStored + globalLazy;
        cout << finalAnswer << "\n";
    }
}

int main() {
    samin_solved();
    return 0;
}
