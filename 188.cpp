#include <bits/stdc++.h>
using namespace std;
#define ll long long

// 0 buy 1 sell

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> curr(2, vector<int>(k+1, 0)), ahead(2, vector<int>(k+1, 0));
        for (int day = n-1; day >= 0; day--){
            for (int buy = 0; buy <= 1; buy++){
                for (int cap = 1; cap <= k; cap++){
                    if(buy==0) curr[buy][cap] = max(
                        -prices[day]+ahead[1][cap],
                        ahead[0][cap]
                    );
                    else curr[buy][cap] = max(
                        prices[day]+ahead[0][cap-1],
                        ahead[1][cap]
                    );
                }   
            }
            ahead = curr;
        }
        return curr[0][k];
    }
};