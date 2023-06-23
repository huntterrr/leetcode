class Solution{
  public:
    int f(int x){
        long long left = 0, right = x, mid;
        while (right>=left)
        {
            mid = left+(right-left)/2;
            if (pow(mid, 2)<=x and pow(mid+1, 2)>x)
            {
                return mid;
            }
            else if(pow(mid, 2)>=x){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return mid;
    }

    int mySqrt(int x){
        return f(x);   
    }

};