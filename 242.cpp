#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        int answer = 1, answer2 = 1, n = s.length(), m = t.length();
        if (n!=m){
            return false;
        }
        unordered_map<char, int> mapS;
        unordered_map<char, int> mapT;
        for (int i = 0; i < n; i++)
        {
            mapS[s[i]] ++;
            mapT[t[i]] ++;
        }
        
        for (char i = 'a'; i <= 'z'; i++)
        {
            if(mapS[i]!=mapT[i]){
                return false;
            }
        }
        return true;
    }
};
