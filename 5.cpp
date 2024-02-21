#include <bits/stdc++.h>
#pragma GCC optimize("03")
using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), longest = 0;
        string res = "";
        for (int i = 0; i < n; i++){
            int l = i, r = i;
            while (l>=0 and l<n and r>=0 and r<n and s[l]==s[r])
            {
                if (r-l+1>longest)
                {
                    longest = r-l+1;
                    res = s.substr(l, r-l+1);
                }
                l--;
                r++;
            }

            l = i, r = i+1;
            while (l>=0 and l<n and r>=0 and r<n and s[l]==s[r])
            {
                if (r-l+1>longest)
                {
                    longest = r-l+1;
                    res = s.substr(l, r-l+1);
                }
                l--;
                r++;
            }
        }
        return res;
    }
};