#include <bits/stdc++.h>
using namespace std;

void solved(){
    int n;
    cin >> n;
    int minqueues = INT_MAX;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        minqueues = min(minqueues, a[i] + i);  // i = steps to reach
        
    }
    cout << minqueues << endl;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        solved();
    }
}
