class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> vec;
        vector<int> subset;
        permutation(vec, nums, subset);
        return vec;
    }
private:
    void permutation(vector<vector<int>> &res, vector<int> &nums, vector<int> &subset){
        if (subset.size()==nums.size())
        {
            res.push_back(subset);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            bool is = true;
            for (int j = 0; j < subset.size(); j++)
            {
                if (subset[j]==nums[i])
                {
                    is = false;
                    break;
                }
            }
            if (is)
            {
                subset.push_back(nums[i]);
                permutation(res, nums, subset);
                subset.pop_back();
            }
        }
    }
};