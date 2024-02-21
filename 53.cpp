#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int inter = 0, res = INT_MIN, n = nums.size();
        for (int i = 0; i < n; i++){
            inter+=nums[i];
            if(nums[i]>inter) inter = nums[i];
            res = max(res, inter);
        }
        return res;
    }
};