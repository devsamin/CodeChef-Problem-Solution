#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
        int n,x,y;
        cin>>n>>x>>y;
        string num;
        cin>>num;

        int dx = num[x - 1] - '0';
        int dy = num[y - 1] - '0';

        if ((dx != 0 && dy % dx == 0) || 
        (dy != 0 && dx % dy == 0)) {
        cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    return 0;
}