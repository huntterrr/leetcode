#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pld[2001][2001];
    int dp[2001];
    bool isPalindrome(int i, int j, string &s){
        if(i>=j) return 1;
        if(pld[i][j]!=-1) return pld[i][j];
        if(s[i]==s[j]) return pld[i][j] = isPalindrome(i+1, j-1, s);
        return pld[i][j] = 0;
    }

    int minCut(string s) {
        int n = s.size();
        memset(pld, -1, sizeof(pld));\
        dp[n] = 0;
        for (int i = n-1; i >= 0; i--){
            int res = INT_MAX;
            for (int j = i; j < n; j++){
                if(isPalindrome(i, j, s)){
                    res = min(res, dp[j+1]+1);
                }
            }
            dp[i] = res;
        }

        return dp[0]-1;
    }
};