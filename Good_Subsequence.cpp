#include <bits/stdc++.h>
using namespace std;

void solved_samin() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << 0 << endl;
        return;
    }
    
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    int length = 1;
    int last_parity = a[0] % 2;
    
    for (int i = 1; i < n; ++i) {
        if ((a[i] % 2) != last_parity) {
            length++;
            last_parity = a[i] % 2;
        }
    }
    
    cout << length << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solved_samin();
    }
    
    return 0;
}