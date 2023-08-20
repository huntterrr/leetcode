#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0, n = nums.size();

		for (int i = 0; i < n; i++){
			sum+=nums[i];
		}

		if (sum%2==1){
			return 0;
		}
		
		vector<int> dp(sum/2 + 1);

		dp[0] = 1;
		
		for (int i = 0; i < n; i++)
		{
			for (int j = sum/2; j >= nums[i]; j--)
			{
				dp[j] = dp[j] or dp[j-nums[i]];
			}
		}
		
		return dp[sum/2];
    }
};