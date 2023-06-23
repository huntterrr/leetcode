class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size(), left = 0, right = n-1, mid;
        
        while (left<=right)
        {
            mid = left + (right-left)/2;
            if (left==right) {
                return left;
            }
            if (nums[mid]<nums[mid+1] and mid<n-1){
                left = mid +1;
            }
            else if(nums[mid]<nums[mid-1] and mid>0){
                right = mid-1;
            }
            else{
                return mid;
            }
        }
        return -1;
    }
};
