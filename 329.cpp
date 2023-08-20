class Solution {
vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
vector<vector<int>> dp;
private:
	int dfs(int i, int j, int n, int m, vector<vector<int>> &matrix){
		if (dp[i][j]!=-1)
		{
			return dp[i][j];
		}
		int len = 1;
		for (auto it: dirs)
		{
			int newi = i + it.first;
			int newj = j + it.second;
			if (newi>=0 and newi<n and newj>=0 and newj<m and matrix[newi][newj]>matrix[i][j]){
				len = max(1 + dfs(newi, newj, n, m, matrix), len);
			}
		}
		dp[i][j] = len;
		return len;		
	}
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
		int n = matrix.size(), m = matrix[0].size(), res = 0;
		dp.resize(n, vector<int>(m, -1));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				res = max(res, dfs(i, j, n, m, matrix));
			}
			
		}
		return res;
    }

};