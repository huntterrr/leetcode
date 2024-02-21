class Solution {
public:
    int subArray(vector<int>& nums, int k) {
        int l = 0, n = nums.size(), res = 0;
        unordered_map<int, int> mp;
        for (int r = 0; r < n; r++){
            mp[nums[r]]++;
            while (mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0) mp.erase(nums[l]);
                l++;
            }
            res+=(r-l+1);
        }
        return res;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subArray(nums, k)-subArray(nums, k-1);
    }
};