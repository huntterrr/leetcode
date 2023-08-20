//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if(grid[i][j]=='1'){
                    dfs(grid, i, j, n, m);
                    cnt++;
                }
            }
        }
        return cnt;
    }
private:
    void dfs(vector<vector<char>>& grid, int i, int j, int n, int m){
        if (i<0 or i>=n or j<0 or j>=m or grid[i][j]=='0')
        {
            return;
        }
        grid[i][j] = '0';

        dfs(grid, i+1, j, n, m);
        dfs(grid, i, j+1, n, m);
        dfs(grid, i, j-1, n, m);
        dfs(grid, i-1, j, n, m);
    }

};