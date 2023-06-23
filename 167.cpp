#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> answer(2);
        int left = 0, right = numbers.size()-1, k;
        while (left<right)
        {
            k = numbers[left]+numbers[right];
            if(k==target){
                answer = {left+1, right+1};
                return answer;
            }
            else if(k>target){
                right--;
            }
            else{
                left++;
            }
        }
        return answer;
    }
};