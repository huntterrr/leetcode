#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, total = 0, res = numeric_limits<int>::max();



        for (int right = 0; right < nums.size(); right++)
        {
            total+=nums[right];
            while (total>=target){
                res = min(right-left+1, res);
                total-=nums[left];
                left++;
            }
        }


        if (res != numeric_limits<int>::max()){
            return res;
        }
        return 0;
    }
};