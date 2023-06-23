#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<int> answer;
        int frequentValue = -1, frequentKey;
        for (int i:nums)
        {
            mp[i]++;
        }
        for (int i = 0; i < k; i++)
        {
            for(auto j = mp.begin(); j!=mp.end(); j++){
                if (j->second>frequentValue)
                {
                    frequentValue = j->second;
                    frequentKey = j->first;
                }
            }
            answer.push_back(frequentKey);
            mp.erase(frequentKey);
            frequentValue = -1;
        }        
        return answer;
    }
};
