#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here

    string s;
    cin>>s;

    string c = "act";
    sort(s.begin(), s.end());

    if (s == c) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

}
