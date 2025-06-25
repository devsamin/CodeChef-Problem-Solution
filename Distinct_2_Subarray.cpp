#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i = 0;i<n;i++){
            cin>>a[i];
        }
        set<int> s;
        for(int i = 0;i<a.size();i++){
            s.insert(a[i]);
        }
        if(s.value == 2){
            
        }
    }
    return 0;
}