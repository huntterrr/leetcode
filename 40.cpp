#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> subset;
        dfs(res, candidates, subset, target, 0, 0);
        return res;
    }
private:
    void dfs(vector<vector<int>> &res, vector<int> &nums, vector<int> &subset, int target, int sum, int start){
        if (sum>target)
        {
            return;
        }
        else if(sum==target){
            res.push_back(subset);
            return;
        }

        for (int i = start; i < nums.size(); i++)
        {
            if (i>start and nums[i]==nums[i-1])
            {
                continue;
            }
            subset.push_back(nums[i]);
            dfs(res, nums, subset, target, sum+nums[i], i+1);
            subset.pop_back();
        }       
    }
};