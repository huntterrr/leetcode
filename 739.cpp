#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<pair<int, int>> stk;
        vector<int> answer(n);
        for (int i = 0; i < n; i++)
        {
            while (!stk.empty() and stk.top().first<temperatures[i])
            {
                answer[stk.top().second] = i-stk.top().second;
                stk.pop();
            }
            stk.push({temperatures[i], i});
        }
        return answer;
    }
};