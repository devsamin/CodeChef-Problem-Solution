#include <bits/stdc++.h>
using namespace std;

void solved_samin() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    
    vector<int> block_values;
    if (n > 0) {
        block_values.push_back(a[0]);
        for (int i = 1; i < n; i++) {
            if (a[i] != a[i-1]) {
                block_values.push_back(a[i]);
            }
        }
    }
    
    int num_blocks = block_values.size();
    
   
    if (num_blocks <= 1) {
        cout << 0 << endl;
        return;
    }

    
    vector<int> tails;
    for (int val : block_values) {
        
        auto it = upper_bound(tails.begin(), tails.end(), val);
        
        if (it == tails.end()) {
            
            tails.push_back(val);
        } else {
           
            *it = val;
        }
    }
    
    int lis_length = tails.size();

    int min_operations = num_blocks - lis_length;
    cout << min_operations << endl;
}

int main() {
   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solved_samin();
    }

    return 0;
}