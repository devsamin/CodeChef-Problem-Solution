#include <bits/stdc++.h>
using namespace std;

void solve_samin() {
    int n;
    cin >> n;

    int odd_stone_count = 0;
    int even_stone_count = 0; 

    for (int i = 0; i < n; ++i) {
        int stone_val;
        cin >> stone_val;
        if (stone_val % 2 == 0) {
            even_stone_count++;
        } else {
            odd_stone_count++;
        }
    }

   
    int odd_pos_cnt = (n + 1) / 2; 
    int even_pos_cnt = n / 2;

    
    bool possible_all_even_sum = (odd_stone_count == odd_pos_cnt && even_stone_count == even_pos_cnt);

   
    bool possible_all_odd_sum = (odd_stone_count == even_pos_cnt && even_stone_count == odd_pos_cnt);

    if (possible_all_even_sum || possible_all_odd_sum) {
        std::cout << "YES"<<endl;
    } else {
        std::cout << "NO"<<endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);                  

    int t; 
    cin >> t;
    while (t--) { 
        solve_samin();
    }
    return 0;
}