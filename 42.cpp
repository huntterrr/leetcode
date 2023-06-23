#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0, left = 0, right = height.size()-1, left_max = height[left], right_max = height[right];
        while (left<right){
            if (left_max<right_max)
            {
                left++;
                left_max = max(left_max, height[left]);
                res += left_max-height[left];
            }
            else{
                right--;
                right_max = max(right_max, height[right]);
                res += right_max-height[right];
            }
            
        }
        return res;
    }
};