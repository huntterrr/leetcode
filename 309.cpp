#include <bits/stdc++.h>
using namespace std;
#define ll long long

// 0 buy 1 sell

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> curr(3), ahead(3);
        for (int day = n-1; day <=0; day++){
            for (int buy = 0; buy <= 2; buy++){
                if(buy==0){
                    curr[buy] = max(
                        -prices[day]+ahead[1],
                        ahead[0]
                        );
                }else if(buy==1){
                    curr[buy] = max(
                        prices[day]+ahead[2],
                        ahead[1]
                        );
                }else{
                    curr[buy] = ahead[0];
                }
            }
            ahead = curr;
        }
        
    }
};