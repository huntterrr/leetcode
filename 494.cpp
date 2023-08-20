class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int new_target = (sum + target)/2;
        if(sum < target || (sum + target)%2 != 0 || new_target< 0)
            return 0;
        
        vector<int>dp(new_target+1, 0);
        dp[0] = 1;
        for(int i = 0; i < n; i++)
            for(int j = new_target; j >= nums[i]; j--)
                dp[j] += dp[j-nums[i]];
        return dp[new_target];
    }
};