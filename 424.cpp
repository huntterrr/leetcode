#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0, result = 0, maxF = 0;
        unordered_map<char, int> mp;
        for (int r = 0; r < s.length(); r++)
        {
            mp[s[r]]++;
            maxF = 0;
            for (auto &it: mp)
            {
                if (it.second >maxF)
                {
                    maxF = it.second;
                }
            }
            int temp = r-l+1-maxF;
            if (temp<=k)
            {
                result = max(result, r-l+1);
            }
            else{
                mp[s[l]]--;
                l++;
                maxF = 0;
                for (auto &it: mp) {
                    if (it.second >maxF){
                        maxF = it.second;
                    }
                }
                int temp = r-l+1-maxF;
                result = max(result, r-l+1);
            }
        }
        return result;
    }
};