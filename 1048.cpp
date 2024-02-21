#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int check(string s1, string s2){
        int n = s1.size(), m = s2.size(), i = 0, j = 0;
        if(n+1!=m){
            return false;
        }        
        while (i < n && j < m) {
            if (s1[i] == s2[j]) {
                i++;
            }
            j++;
        }

        return i == s1.length();
    }
    int comparator(string &s1, string &s2){
        return s1.size()<s2.size();
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string &s1, const string &s2){ return s1.length()<s2.length();});
        int n = words.size(), maxi = 1;
        vector<int> dp(n, 1);
        for (int i = n-2; i >= 0; i--){
            for (int j = i+1; j < n; j++){
                if (dp[j]+1>dp[i] and check(words[i],words[j])){
                    dp[i] = dp[j]+1;
                }
            }
            if(dp[i]>maxi) maxi = dp[i];
        }

        return maxi;
    }
};