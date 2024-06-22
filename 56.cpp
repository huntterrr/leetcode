class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(begin(intervals), end(intervals));
        int s = intervals[0][0], e = intervals[0][1];
        for(int i = 1;i<intervals.size();i++){
            if(intervals[i][0]>=s and intervals[i][0]<=e){
                e = max(e, intervals[i][1]);
            }else{
                res.push_back({s, e});
                s = intervals[i][0];
                e = intervals[i][1];
            }
        }
        res.push_back({s, e});
        return res;
    }
};