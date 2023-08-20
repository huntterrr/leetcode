#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        dfs(res, board, 0, n);
        return res;
    }

private:
    bool isSafe(const vector<string>& board, int row, int col, int n) {
        // Check upper diagonal
        int i = row - 1, j = col - 1;
        while (i >= 0 && j >= 0) {
            if (board[i][j] == 'Q') {
                return false;
            }
            i--;
            j--;
        }

        // Check lower diagonal
        i = row - 1;
        j = col + 1;
        while (i >= 0 && j < n) {
            if (board[i][j] == 'Q') {
                return false;
            }
            i--;
            j++;
        }

        // Check row
        i = row-1;
        j = col;
        while (i >= 0) {
            if (board[i][j] == 'Q') {
                return false;
            }
            i--;
        }

        return true;
    }

    void dfs(vector<vector<string>>& res, vector<string>& board, int row, int n) {
        if (row == n) {
            res.push_back(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(board, row, col, n)) {
                board[row][col] = 'Q';
                dfs(res, board, row + 1, n);
                board[row][col] = '.';
            }
        }
    }
};
