#include <bits/stdc++.h>
using namespace std;


void samin_solved(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
    }

    int minCost = INT_MAX;
    for(int i=0;i<n-1;i++){
        int minC = v[i] + (v[i+1]/2);
        minCost = min(minC, minCost);
    }

    sort(v.begin(), v.end());
    int minC2 = v[0] + v[1];

    cout << min(minCost, minC2) << endl;

}

int main() {
	// your code goes here

    int t;
    cin>>t;
    while(t--){
        samin_solved();
    }

}
