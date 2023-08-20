#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, 0, i, j)) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
private:
    bool dfs(vector<vector<char>>& board, string word,
        int index, int i, int j) {
        if (i<0 or i>=board.size() or j<0 or j>=board[0].size() or board[i][j]!=word[index])
        {
            return false;
        }

        if (index==word.size()-1)
        {
            return true;
        }
        board[i][j] = '*';
        // top
        if(dfs(board, word, index+1, i-1, j) or
        // bottom
        dfs(board, word, index+1, i+1, j) or
        // right
        dfs(board, word, index+1, i, j+1) or
        // left
        dfs(board, word, index+1, i, j-1)
        ){
            return true;
        }
        board[i][j] = word[index];
        return false;
    }
};