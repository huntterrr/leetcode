class Solution {
public:
    int lcs(string s1, string s2){
        int n = s1.size();
        int m = s2.size();
        int res = 0;
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=m; j++){
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                    res = max(res, dp[i][j]);
                }
            }
        }
        return res;
    }
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        return lcs(s, t);
    }
};