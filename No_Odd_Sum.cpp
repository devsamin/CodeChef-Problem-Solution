#include <iostream>
using namespace std;

void solved() {
    int n;
    cin >> n;
    int c1 = 0, c2 = 0;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(x == 1) c1++;
        else c2++;
    }

    int operations = 0;

    if(c1 == 0 || c2 == 0) {
        operations = 0; // already good
    }
    else if(c1 % 2 == 0) {
        // try converting 1s → 2s
        operations = min(c1 / 2, c2);
    }
    else {
        // c1 is odd → can't make all 2s, so convert all 2s → 1s
        operations = c2;
    }

    cout << operations << endl;
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        solved();
    }
    return 0;
}
