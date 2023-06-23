#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0, right = 0, maxx = 0;
        while (right<prices.size())
        {
            if (prices[right]>prices[left])
            {
                maxx = max(prices[right]-prices[left], maxx);
            }
            else{
                left = right;
            }
                right++;
        }
        return maxx;
        
    }
};