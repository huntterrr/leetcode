#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        vector<vector<int>> res(n, vector<int>(m));
        vector<vector<int>> vis(n, vector<int>(m));
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j]==0)
                {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
            }
        }
        while (!q.empty())
        {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            res[i][j] = dist;
            for (vector<int> &k: dir)
            {
                int x = i+k[0];
                int y = j+k[1];
                if (x>=0 and y>=0 and x<n and y<m and !vis[x][y])
                {
                    q.push({{x, y}, dist+1});
                    vis[x][y] = 1;
                }
            }
            

        }
        return res;
        
    }
};
