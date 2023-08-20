#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> pasific(heights.size(), vector<int>(heights[0].size()));
        vector<vector<int>> atlantik(heights.size(), vector<int>(heights[0].size()));
        vector<vector<int>> res;
        for (int i = 0; i < m; i++)
        {
            dfs(n, m, 0, i, INT_MIN, pasific, heights);
            dfs(n, m, n-1, i, INT_MIN, atlantik, heights);
        }
        for (int i = 0; i < n; i++)
        {
            dfs(n, m, i, 0, INT_MIN, pasific, heights);
            dfs(n, m, i, m-1, INT_MIN, atlantik, heights);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (atlantik[i][j]==1 and pasific[i][j]==1)
                {
                    vector<int> vec = {i, j};
                    res.push_back(vec);
                }
            }   
        }
        return res;
    }
private:
    void dfs(int n, int m, int i, int j, int prev, vector<vector<int>> &ocean, vector<vector<int>> &heights){
        if (i<0 or i>=n or j<0 or j>=m or ocean[i][j]==1 or heights[i][j]<prev)
        {
            return;
        }
        ocean[i][j] = 1;
        dfs(n, m, i+1, j, heights[i][j], ocean, heights);
        dfs(n, m, i-1, j, heights[i][j], ocean, heights);
        dfs(n, m, i, j+1, heights[i][j], ocean, heights);
        dfs(n, m, i, j-1, heights[i][j], ocean, heights);
    }
};