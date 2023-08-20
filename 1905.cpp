#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
bool res;
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        int ans = 0;
        for (int i = 0; i < grid1.size(); i++){
            for (int j = 0; j < grid1[0].size(); j++){
                if (grid2[i][j]){
                    res = true;
                    dfs(grid1, grid2, n, m, i, j);
                    if (res) ans++;   
                }
            }
        }
        return ans;
    }

    void dfs(vector<vector<int>> &grid1, vector<vector<int>> &grid2, int n, int m, int i, int j){
        if (i>=n or i<0 or j>=m or j<0 or !grid2[i][j]) return;

        if (grid1[i][j]==0){
            res = false;
            return;
        }
        
        grid2[i][j] = 0;

        dfs(grid1, grid2, n, m, i-1, j);
        dfs(grid1, grid2, n, m, i+1, j);
        dfs(grid1, grid2, n, m, i, j-1);
        dfs(grid1, grid2, n, m, i, j+1);
    }
};