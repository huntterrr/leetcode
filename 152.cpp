class Solution {
public:
    int maxProduct(vector<int>& a) {
        int n = a.size();
        int maxRes = 1, minRes = 1, res = INT_MIN;
        for(int i = 0; i < n; i++){
            if(a[i]<0) swap(maxRes, minRes);
            maxRes = max(maxRes*a[i], a[i]);
            minRes = min(minRes*a[i], a[i]);
            res = max(res, maxRes);
        }
        return res;
    }
};