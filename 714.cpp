#include <bits/stdc++.h>
using namespace std;
#define ll long long

// 0 buy 1 sell

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> curr(2), ahead(2);
        for (int day = n-1; day >= 0; day--){
            for (int buy = 0; buy <= 1; buy++){
                if (buy==0){
                    curr[buy] = max(
                        -prices[day]+ahead[1],
                        ahead[0]
                    );
                } else{
                    curr[buy] = max(
                        prices[day]-fee+ahead[0],
                        ahead[1]
                    );
                }                 
            }
            ahead = curr;
        }
        return curr[0];
    }
};