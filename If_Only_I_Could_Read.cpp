#include <bits/stdc++.h>
using namespace std;

void samin_solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Iterate over all possible starting points
    for (int i = 0; i < n; i++) {
        // Iterate over even-length subarrays starting at i
        for (int len = 2; i + len - 1 < n; len += 2) {
            int j = i + len - 1; // Ending index
            vector<int> subarray(a.begin() + i, a.begin() + j + 1);
            
            // Chef's median: element at position len/2 (0-based index)
            int chef_median = subarray[len / 2 - 1];
            
            // True median: sort and take element at position len/2
            sort(subarray.begin(), subarray.end());
            int true_median = subarray[len / 2 - 1];
            
            // If medians differ, output 1-based indices and return
            if (chef_median != true_median) {
                cout << i + 1 << " " << j + 1 << endl;
                return;
            }
        }
    }
    
    // No valid subarray found
    cout << -1 << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        samin_solve();
    }
    
    return 0;
}