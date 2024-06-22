class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<bool> vec(n+1, 0);
        for(int i: nums){
            if(vec[i]) return i;
            vec[i] = 1;
        }
        return -1;
    }
};