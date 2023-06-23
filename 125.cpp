#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        // s.erase(remove(s.begin(), s.end(), ' '), s.end());
        string str = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (isalnum(s[i]))
            {
                str += tolower(s[i]);
            }
            
        }
        int i = 0, j = str.length()-1;
        while (j>=i)
        {
            if (str[i]!=str[j])
            {
                return false;
            }
            i++;j--;
        }
        return true;
    }
};