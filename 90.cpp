#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> subset = {};
        dfs(res, nums, subset, 0);

        return res;

    }
private:
    bool areVectorsEqual(const std::vector<int>& vector1, const std::vector<int>& vector2) {
        if (vector1.size() != vector2.size()) {
            return false;
        }

        for (size_t i = 0; i < vector1.size(); i++) {
            if (vector1[i] != vector2[i]) {
                return false;
            }
        }

        return true;
    }

    void dfs(vector<vector<int>> &ans, vector<int> &nums, vector<int> &subset, int start){
        if (start>=nums.size())
        {
            if (start >= nums.size()) {
                bool isDuplicate = false;
                for (const auto& existing : ans) {
                    if (areVectorsEqual(subset, existing)) {
                        isDuplicate = true;
                        break;
                    }
                }
                if (!isDuplicate) {
                    ans.push_back(subset);
                }
                return;
            }
        }

        subset.push_back(nums[start]);
        dfs(ans, nums, subset, start+1);
        subset.pop_back();
        dfs(ans, nums, subset, start+1);
    }
};
