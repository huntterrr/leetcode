#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string& s) {
        int l = 0;
        int answer = 0;
        unordered_set<char> st;
        for (int r = 0; r < s.size(); r++)
        {
            if (st.count(s[r])==0)
            {
                st.insert(s[r]);
                answer = max(answer, r-l+1);
            }else{
                while (st.count(s[r]))
                {
                    st.erase(s[l]);
                    l++;
                }
                st.insert(s[r]);
            }
        }
        return answer;
    }
};