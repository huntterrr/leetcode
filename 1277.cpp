class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), sum = matrix[0][0];
        for (int i = 1; i < n; i++)sum+=matrix[i][0];
        for (int j = 1; j < m; j++)sum+=matrix[0][j];
        
        for (int i = 1; i < n; i++){
            for (int j = 1; j < m; j++){
                if(matrix[i][j]) matrix[i][j]+=min(matrix[i-1][j], min(matrix[i-1][j-1], matrix[i][j-1]));
                sum+=matrix[i][j];
            }
        }
        return sum;
    }
};