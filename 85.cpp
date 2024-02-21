class Solution {
public:
    int f(vector<int>& heights) {
        int n = heights.size();
        vector<int> rightSmaller(n), leftSmaller(n);
        // left smaller count
        stack<int> stk;
        for (int i = 0; i < n; i++){
            while (!stk.empty() and heights[stk.top()]>=heights[i]){
                stk.pop();
            }
            if(stk.empty()) leftSmaller[i] = 0;
            else leftSmaller[i] = stk.top()+1;
            stk.push(i);
        }
        // right smaller
        while (!stk.empty()) stk.pop();
        
        for (int i = n-1; i >= 0; i--){
            while (!stk.empty() and heights[stk.top()]>=heights[i]){
                stk.pop();
            }
            if(stk.empty()) rightSmaller[i] = n-1;
            else rightSmaller[i] = stk.top()-1;
            stk.push(i);
        }

        int res = 0;
        for (int i = 0; i < n; i++){
            res = max(res, heights[i]*(rightSmaller[i]-leftSmaller[i]+1));
        }
        return res;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), res = 0;
        vector<int> heights(m, 0);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if(matrix[i][j]=='1'){
                    heights[j]++;
                }else heights[j] = 0;
            }
            res = max(res, f(heights));
        }
        return res;
    }
};