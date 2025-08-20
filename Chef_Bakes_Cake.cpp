#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, y;
    cin >> n >> x >> y;

    int capacity = y / x;

    int vehicles = (n + capacity - 1) / capacity;

    cout << vehicles << endl;
    return 0;
}
