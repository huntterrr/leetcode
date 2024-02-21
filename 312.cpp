class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int dp[303][303];
        for (int i = n; i >= 1; i--){
            for (int j = i; j <= n; j++){
                int maxi = INT_MIN;
                for (int k = i; k <= j; k++){
                    maxi = max(maxi, 
                    nums[i-1]*nums[k]*nums[j+1]+dp[i][k-1]+dp[k+1][j]);
                }                
                dp[i][j] = maxi;
            }
        }
        return dp[1][n];
    }
};