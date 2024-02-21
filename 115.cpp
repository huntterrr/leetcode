#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        long long mod = pow(10, 9)+7;
        long long m = t.size();
        long long n = s.size();
        vector<int> prev(n+1, 0);
        for(long long j = 0; j<=n; j++){
            prev[j] = 1;
        }
        for(long long i = 1; i<=m; i++){
            vector<int> curr(n+1, 0);
            for(long long j = i; j<=n; j++){
                curr[j] = curr[j-1]%mod;
                if(s[j-1]==t[i-1]){
                    curr[j] = (prev[j-1]+curr[j-1])%mod;
                }
            }
            prev = curr;
        }
        return prev[n];
    }
};