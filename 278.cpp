class Solution {
public:
    int firstBadVersion(int n) {
        long low=1;
        long high=n;
        long mid;
        
        while(low<=high){
            mid=(low+high)/2;

            if(isBadVersion(mid)){

                if(!isBadVersion(mid-1)){ 
                    return mid;
                }
                else high=mid-1;
            }

            else{
                low=mid+1;
            }
        }
        return mid;
    }
};