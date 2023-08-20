#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int n = image.size();
        int m = image[0].size();
        int def = image[sr][sc];
        if (def == newColor) {
            return image;
        }
        dfs(image, sr, sc, newColor, n, m, def);
        return image;
    }

private:
    void dfs(vector<vector<int>> &image, int sr, int sc, int color, int n, int m, int def){
        if (sr<0 or sr>=n or sc<0 or sc>=m or image[sr][sc]!=def)
        {
            return;
        }
        image[sr][sc] = color;

        dfs(image, sr-1, sc, color, n, m, def);
        dfs(image, sr+1, sc, color, n, m, def);
        dfs(image, sr, sc-1, color, n, m, def);
        dfs(image, sr, sc+1, color, n, m, def);
    }

};