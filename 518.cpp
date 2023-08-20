class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
		vector<int> dp(amount+1, 0);
		dp[0] = 1;

		for (int i = coins[0]; i < amount+1; i++)
		{
			if (i%coins[0]==0){
				dp[i] = 1;
			}
		}

		for (int i = 1; i < n; i++)
		{
			for (int j = coins[i]; j <= amount; j++)
			{
				dp[j]+=dp[j-coins[i]];
			}
		}
		return dp[amount];
    }
};