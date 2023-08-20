#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        for (int i = 0; i < m; i++)
        {
            dfs(n, m, 0, i, grid);
            dfs(n, m, grid.size()-1, i, grid);
        }
        for (int i = 0; i < n; i++)
        {
            dfs(n, m, i, 0, grid);
            dfs(n, m, i, grid[0].size()-1, grid);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j]==1)
                {
                    res++;
                }
            }
        }
        return res;
    }
private:
    void dfs(int n, int m, int i, int j, vector<vector<int>> &grid){
        if (i<0 or i>=n or j<0 or j>=m or grid[i][j]==0)
        {
            return;
        }
        grid[i][j] = 0;
        dfs(n, m, i+1, j, grid);
        dfs(n, m, i-1, j, grid);
        dfs(n, m, i, j+1, grid);
        dfs(n, m, i, j-1, grid);
    }
};