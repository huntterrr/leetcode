class Solution {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
        vector<int> res;
        int i = 0, j = 0;
        while(i<m and j<n){
            if(a[i]<b[j]){
                res.push_back(a[i]);
                i++;
            }else{
                res.push_back(b[j]);
                j++;
            }
        }
        while(i<m){
            res.push_back(a[i]);
            i++;
        }
        while(j<n){
            res.push_back(b[j]);
            j++;
        }
        a = res;
    }
};