#include <bits/stdc++.h>
using namespace std;

// 0 buy 1 sell
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> curr(2, vector<int>(3)), ahead(2, vector<int>(3));

        for (int day = n-1; day >= 0; day--){
            for (int buy = 0; buy <= 1; buy++){
                for (int cap = 1; cap <= 2; cap++){
                    if (buy==0){ // we can buy
                        curr[buy][cap] = max(-prices[day]+ahead[1][cap], ahead[0][cap]);
                    }
                    else{
                        curr[buy][cap] = max(prices[day] + ahead[0][cap-1], ahead[1][cap]);
                    }
                }
            }
            ahead = curr;
        }
        return curr[0][2];
    }
};
