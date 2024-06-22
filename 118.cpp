class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> vec = {{1}};
        for(int i = 2;i<=numRows;i++){
            vector<int> temp(i, 1);
            for(int j = 1;j<i-1;j++){
                temp[j] = vec[i-2][j]+vec[i-2][j-1];
            }
            vec.push_back(temp);
        }
        return vec;
    }
};