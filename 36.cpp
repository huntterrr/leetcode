#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int cnt = 9;
        
        // check rows
        
        for (int i = 0; i < cnt; i++)
        {
            vector<char> control = board[i];
            sort(control.begin(), control.end());
            for (int j = 0; j < cnt-1; j++)
            {
                if (control[j]==control[j+1] and control[j]!='.')
                {
                    return false;
                }
            }
        }

        // check columns

        for (int i = 0; i < cnt; i++)
        {
            vector<char> control2 = {};
            for (int j = 0; j < cnt; j++)
            {
                control2.push_back(board[j][i]);
            }

            sort(control2.begin(), control2.end());
            
            for (int j = 0; j < cnt-1; j++)
            {
                if (control2[j]==control2[j+1] and control2[j]!='.')
                {
                    return false;
                }
            }
        }

        // check 3*3 boxes

        for (int i = 0; i < cnt; i+=3){
            for (int j = 0; j < cnt; j+=3){
                vector<char> control3 = {};
                for (int k = 0; k < 3; k++){
                    for (int l = 0; l < 3; l++){
                        control3.push_back(board[i+k][j+l]);
                    }
                }
                sort(control3.begin(), control3.end());
                for (int u = 0; u < control3.size()-1; u++){
                    if (control3[u]==control3[u+1] and control3[u]!='.'){
                        return false;
                    }
                }
            }
        }

    return true;
    }
};
