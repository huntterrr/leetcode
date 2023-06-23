#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, result = nums[0];
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[left]<nums[right])
            {
                result = min(result, nums[left]);
                return result;
            }
            result = min(result, nums[mid]);
            if (nums[left]<=nums[mid])
            {
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return result;
    }
};
