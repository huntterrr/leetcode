#include <bits/stdc++.h>
#pragma GCC optimize("03")
using namespace std;
#define ll long long

class Solution {
public:
    bool isMatch(string s2, string s1) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        dp[0][0] = 1;
        for(int i = 1;i<=n and s1[i-1]=='*'; i++){
            dp[i][0] = 1;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++){
                if(s1[i-1]=='*'){
                    dp[i][j] = dp[i-1][j] or dp[i][j-1];
                }else{
                    dp[i][j] = (s1[i - 1] == s2[j - 1] || s1[i - 1] == '?') && dp[i - 1][j - 1];
                }
            }
        }
        
        return dp[n][m];

    }
};