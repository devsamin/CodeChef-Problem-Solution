#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int oddmaxgym = 0;
        int evenmaxgym = 0;
        for(int i=0;i<n;i+=2){
            oddmaxgym+=arr[i];
        }
        for(int i=1;i<n;i+=2){
            evenmaxgym+=arr[i];
        }
        cout<<max(evenmaxgym, oddmaxgym)<<endl;
    }
    return 0;
}