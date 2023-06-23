#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(), answer = -1, i = 0, j = height.size()-1;
        while (i<j)
        {
            answer = max(answer, min(height[i], height[j]) * (j-i));
            if (height[i]>height[j])
            {
                j--;
            } 
            else{
                i++;
            }
            
        }
        
        return answer;
        
    }
};