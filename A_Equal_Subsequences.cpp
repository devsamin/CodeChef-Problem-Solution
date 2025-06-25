#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while (t--) {
        int n, k; 
        cin >> n >> k;

        // k ta '1' and (n-k) ta '0' add korlam
        string s(k, '1');
        s += string(n - k, '0');

        cout << s << endl;
    }

    return 0;
}
