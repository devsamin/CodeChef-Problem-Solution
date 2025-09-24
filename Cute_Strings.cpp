#include <bits/stdc++.h>
using namespace std;

void samin_solved() {
    string s;
    if (!(cin >> s)) return;
    if (s.size() == 3 && s[1] == 'w' && s[0] == s[2]) 
        cout << "Cute\n";
    else 
        cout << "No\n";
}

int main() {
    samin_solved();
    return 0;
}
