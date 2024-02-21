#include <bits/stdc++.h>
using namespace std;
#define ll long long

// first solution(dp)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int res = 1;
        for (int i = n-2; i >= 0; i--){
            for (int j = i+1; j < n; j++){
                if (nums[j]>nums[i] and dp[j]+1>dp[i]){
                    dp[i] = dp[j]+1;
                    res = max(dp[i], res);
                }
                
            }
        }
        return res;
    }
};

// second soltuion(binary search)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> res = {nums[0]};

        for (int i = 1; i < n; i++){
            if(nums[i]>res.back()){
                res.push_back(nums[i]);
                continue;
            }
            
            int l = 0, r = res.size()-1, mid, index;
            while (l<=r){
                mid = (r+l)/2;
                if (res[mid]>=nums[i]){
                    r = mid-1;
                    index = mid;
                }
                else{
                    l = mid+1;
                }
            }
            res[index] = nums[i];
        }

        
        return res.size();
    }
};