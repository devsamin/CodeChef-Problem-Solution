#include<bits/stdc++.h>
using namespace std;
int main(){
    int k = 1;
    int s = 5-1;
    for(int i=1;i<=5;i++){
        for(int j=1;j<=s;j++){
            cout<<" ";
        }
        for(int j=1;j<=k;j++){
            cout<<"*";
        }
        cout<<endl;
        k++;
        s--;
    }
    return 0;
}