class Solution {
public:
    vector<vector<int>> dp;
    int f(int i, int n){
        if(dp[i][n]!=-1) return dp[i][n];
        if(n==0) return dp[i][n] = 1;
        if(i>=5) return dp[i][n] = 0;
        int pick = f(i, n-1);
   		int notPick = f(i+1, n);
   		return dp[i][n] = pick + notPick;
    }
    int countVowelStrings(int n) {
        dp.resize(6, vector<int>(n+1, -1));
        return f(0, n);
    }
};