#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < m; i++)
        {
            dfs(n, m, 0, i, board);
            dfs(n, m, n-1, i, board);
        }
        for (int i = 0; i < n; i++)
        {
            dfs(n, m, i, 0, board);
            dfs(n, m, i, m-1, board);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j]=='O')
                {
                    board[i][j] = 'X';
                }
                else if(board[i][j]=='E'){
                    board[i][j] = 'O';
                }
            }
        }      
    }
private:
    void dfs(int n, int m, int i, int j, vector<vector<char>> &board){
        if (i<0 or i>=n or j<0 or j>=m or board[i][j] !='O')
        {
            return;
        }
        board[i][j] = 'E';
        dfs(n, m, i+1, j, board);
        dfs(n, m, i-1, j, board);
        dfs(n, m, i, j+1, board);
        dfs(n, m, i, j-1, board);
    }
};