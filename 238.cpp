class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int left = 1, right = 1, n = nums.size(), prefix, postfix;
        vector<int> answer(n, 1);
        prefix = 1;
        for (int i = 0; i < n; i++)
        {
            answer[i] = prefix;
            prefix*=nums[i];
        }
        postfix = 1;
        for (int i = n-1; i > -1; i--)
        {
            answer[i]*=postfix;
            postfix*=nums[i];
        }
    return answer;
    }

};
