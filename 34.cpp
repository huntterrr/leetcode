#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        long long left = 0, right = nums.size()-1, mid, left_result = -1, right_result = -1;
        vector<int> answer(2);
        // searching for left one
        while (left<=right)
        {
            mid = (left+right)/2;
            if(nums[mid]==target){
                left_result = mid;
                right = mid-1;
            }
            else if (nums[mid]>target)
            {
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        answer[0] = left_result;

        // searching for the right one
        left = 0, right = nums.size()-1;
        while (left<=right)
        {
            mid = (left+right)/2;
            if(nums[mid]==target){
                right_result = mid;
                left = mid+1;
            }
            else if (nums[mid]>target)
            {
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        answer[1] = right_result;
        return answer;
    }

};