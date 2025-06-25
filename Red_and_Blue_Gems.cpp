#include <bits/stdc++.h>
using namespace std;
int main(){

    int r,b,p,q;
    cin>>r>>b>>p>>q;
    int redmax = r * p;
    int bluemax = b * q;
    int maxsold = max(redmax, bluemax);
    cout<<maxsold<<endl;
    return 0;
}