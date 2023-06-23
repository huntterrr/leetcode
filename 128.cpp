#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numsSet(nums.begin(), nums.end());
        int longest = 0;
        for (auto &i:numsSet)
        {
            if (!numsSet.count(i-1))
            {
                int length = 1;
                while (numsSet.count(i+length))
                {
                    length++;
                }
                longest = max(longest, length);
            }
            
        }
        return longest;
    }
};