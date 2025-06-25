#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i =0;i<n; i++){
        cin>>arr[i];
    }
     vector<int> ans;
        for(int i=0;i<n-2;i++){
            for(int j=i+1; j<=i+1;j++){
                for(int k = j+1;k<=j+1;k++){
                    int val = max({arr[i], arr[j], arr[k]});
                    ans.push_back(val);
                }
            }
        }
        for(int i =0;i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}