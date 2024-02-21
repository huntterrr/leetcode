#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;

        vector<int> dp1(n, 1);
        vector<int> dp2(n, 1); 

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j] && dp1[i] < dp1[j] + 1) {
                    dp1[i] = dp1[j] + 1;
                }
            }
        }

        int maxBitonic = 1;
        for (int i = n-2; i >= 0; i--) {
            for (int j = n-1; j > i; j--) {
                if (nums[i] > nums[j] && dp2[i] < dp2[j]+1) {
                    dp2[i] = dp2[j] + 1;
                }
            }
            if(dp1[i]==1||dp2[i]==1) continue;
            maxBitonic = max(maxBitonic, dp1[i] + dp2[i] - 1);
        }

        return n - maxBitonic;
    }
};
