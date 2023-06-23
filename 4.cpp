class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        long long len = nums1.size()+nums2.size(), len1 = nums1.size(), len2 = nums2.size(), i = 0, j = 0, k = 0;
        long double result;
        vector<int> answer(len);
        while (i<len1 and j<len2)
        {
            if (nums1[i]>nums2[j])
            {
                answer[k] = nums2[j];
                j++;
            }
            else{
                answer[k] = nums1[i];
                i++;
            }
            k++;
        }
        if (i<len1)
        {
            while (i<len1)
            {
                answer[k] = nums1[i];
                k++;i++;
            }
            
        }
        if (j<len2)
        {
            while (j<len2)
            {
                answer[k] = nums2[j];
                k++;j++;
            }           
        }

        if (len%2!=0){
            result = answer[(len-1)/2];
        }
        else{
            result = (answer[len/2]+answer[(len/2)-1])/2.0;
        }
        return result;
    }

};