#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool equal(string s1, string s2){
        unordered_map<char, int> mp;
        for (int i = 0; i < s1.size(); i++)
        {
            mp[s1[i]]++;
            mp[s2[i]]--;
        }
        for (auto &it: mp)
        {
            if (it.second != 0)
            {
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        if (s1.size()>s2.size())
        {
            return false;
        }
        int l = 0, r = s1.size()-1;
        while (r<s2.size())
        {
            string temp = s2.substr(l, r-l+1);
            if (equal(temp, s1))
            {
                return true;
            }
            l++;
            r++;
        }
        return false;
        
    }
};