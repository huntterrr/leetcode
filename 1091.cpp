class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0] or grid[n-1][m-1]) return -1;
        pair<int, int> source = {0, 0}, destination = {n-1, m-1};
        vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        queue<pair<int, int>> q;
        q.push(source);
        dist[source.first][source.second] = 0; // Set the distance of the source cell to 0
        while (!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (auto &it : dirs) {
                int i = x + it.first;
                int j = y + it.second;
                if (i >= 0 && i < n && j >= 0 && j < m && dist[i][j] > dist[x][y] + 1 && grid[i][j] != 1) {
                    dist[i][j] = dist[x][y] + 1;
                    q.push({i, j});
                }
            }

        }
        if(dist[destination.first][destination.second]==1e9) return -1;
        return dist[destination.first][destination.second]+1;
    }
};
