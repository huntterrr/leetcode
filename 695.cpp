#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j]==1)
                {
                    int time = 0;
                    dfs(grid, time, n, m, i, j);
                    cnt = max(cnt, time);
                }
            }
        }
        return cnt;
    }
private:
    void dfs(vector<vector<int>> &grid, int &cnt, int n, int m, int i, int j){
        if (i<0 or i>=n or j<0 or j>=m or grid[i][j]==0)
        {
            return;
        }
        grid[i][j] = 0;
        cnt+=1;
        dfs(grid, cnt, n, m, i+1, j);
        dfs(grid, cnt, n, m, i-1, j);
        dfs(grid, cnt, n, m, i, j+1);
        dfs(grid, cnt, n, m, i, j-1);
    }
};