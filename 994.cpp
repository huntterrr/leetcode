#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        int fresh = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j]==2)
                {
                    q.push({i, j});
                }
                else if (grid[i][j]==1)
                {
                    fresh++;
                }
            }
        }
        int cnt = -1;
        q.push({-1, -1});
        while (!q.empty())
        {
            int left = q.front().first;
            int right = q.front().second;
            q.pop();
            if (left==-1)
            {
                cnt++;
                if(!q.empty()){
                    q.push({-1, -1});
                }
            }
            else{
                for (int i = 0; i < dir.size(); i++)
                {
                    int x = left + dir[i][0];
                    int y = right + dir[i][1];
                    if (x<0 or x>=n or y<0 or y>=m)
                    {
                        continue;
                    }
                    if (grid[x][y]==1)
                    {
                        q.push({x, y});
                        grid[x][y] = 2;
                        fresh--;
                    }   
                }
            }   
        }
        if (fresh==0)
        {
            return cnt;
        }
        return -1;
    }
};