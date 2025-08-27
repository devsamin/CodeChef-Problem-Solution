#include <bits/stdc++.h>
using namespace std;
void solved_samin(){
    int A, B;
        cin >> A >> B;

        int juice_make_syrup = 3 * A;

        int juice_make_water = (B / 2) * 3;

        cout << min(juice_make_syrup, juice_make_water) << endl;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        solved_samin();
    }
    return 0;
}
