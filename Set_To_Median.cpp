#include <bits/stdc++.h>
using namespace std;

void samin_solved() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cases; 
    cin >> cases;
    while(cases--) {
        int len;
        cin >> len;

        vector<long long> nums(len+1);
        for(int i=1; i<=len; i++) cin >> nums[i];
        sort(nums.begin()+1, nums.end());

        vector<long long> cum(len+1, 0);
        for(int i=1; i<=len; i++) cum[i] = cum[i-1] + nums[i];

        long long original = cum[len];
        long long bestBoost = 0;

        for(int pos=1; pos<=len;) {
            int start = pos;
            long long val = nums[pos];
            while(pos<=len && nums[pos]==val) pos++;
            int stop = pos-1;

            int equalCount = stop - start + 1;
            int smallerCount = start - 1;
            int greaterCount = len - stop;

            long long leftPick = min((long long)equalCount-1, (long long)smallerCount);
            long long gainNow = leftPick*val - (cum[leftPick]-cum[0]);

            if(smallerCount > equalCount-1 && greaterCount > 0) {
                int takenLeft = equalCount-1;
                long long low=0, high=min(smallerCount-(equalCount-1), greaterCount), best=0;

                while(low<=high) {
                    long long mid=(low+high)/2;
                    if(mid==0 || nums[takenLeft+mid] + nums[stop+mid] < 2*val) {
                        low=mid+1;
                    } else {
                        high=mid-1;
                    }
                }
                best = high;
                if(best>0) {
                    long long addVal = 2LL*best*val 
                                     - (cum[takenLeft+best]-cum[takenLeft]) 
                                     - (cum[stop+best]-cum[stop]);
                    gainNow += addVal;
                }
            }
            bestBoost = max(bestBoost, gainNow);
        }

        cout << original + max(0LL, bestBoost) << "\n";
    }
}

int main() {
    samin_solved();
    return 0;
}
