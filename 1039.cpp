class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int N = values.size();
        vector<vector<int>> dp(N, vector<int>(N, 0));
        for(int i = N-1; i>0; i--){
            for(int j = i+1; j<N; j++){
                int steps = INT_MAX;
                for(int k = i; k < j; k++){
                    steps = min(steps, values[i-1]*values[j]*values[k] + dp[i][k]+dp[k+1][j]);
                }
                dp[i][j] = steps;
            }
        }
        return dp[1][N-1];
    }
};