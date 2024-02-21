class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        vector<vector<int>> dp(c+2, vector<int>(c+2));
        for(int i = c; i>=1; i--){
            for (int j = i; j <= c; j++){
                int cost = INT_MAX;
                for (int k = i; k <= j; k++){
                    cost = min(cost, dp[i][k-1]+dp[k+1][j]);
                }
                dp[i][j] = cost+cuts[j+1]-cuts[i-1];
            }
        }
        return dp[1][c];
    }
};