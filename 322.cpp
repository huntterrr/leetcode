#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
		int n = coins.size();
  	int Max = amount + 1;
		vector<int> dp(amount+1, 1e9);
		
		dp[0] = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 1; j < amount+1; j++)
			{
				if (j>=coins[i])
				{
					dp[j] = min(dp[j], dp[j-coins[i]]+1);
				}	
			}
		}
		
		return dp[amount] == 1e9 ? -1 : dp[amount];
  }
};