#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size(), left = 0, right = n-1, mid;
        while (left<=right)
        {
            mid = left +(right-left)/2;
            if (n-mid==citations[mid])
            {
                return n-mid;
            }
            else if(n-mid>citations[mid]){
                left = mid+1;
            }
            else{
                right = mid - 1;
            }
        }
        return n-left;
        
    }
};