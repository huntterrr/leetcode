#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size(), maxi = 1, index = 0;
        if (n == 0) return {};
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);
        sort(nums.begin(), nums.end());
        for (int i = n-2; i >= 0; i--){
            for (int j = i+1; j < n; j++){
                if (nums[j]%nums[i]==0 and dp[i]<dp[j]+1){
                    dp[i] = dp[j]+1;
                    prev[i] = j;
                }
            }
            if (dp[i]>maxi){
                maxi = dp[i];
                index = i;
            }
        }

        vector<int> res;
        res.push_back(nums[index]);
        while (prev[index]!=-1){
            index = prev[index];
            res.push_back(nums[index]);
        }
        return res;   
    }
};