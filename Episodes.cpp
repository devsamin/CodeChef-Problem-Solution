#include <bits/stdc++.h>
using namespace std;

void samin_solved() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        int totalMinutes = N * K;
        int H = totalMinutes / 60;
        int M = totalMinutes % 60;

        cout << H << " " << M << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    samin_solved();
    return 0;
}
