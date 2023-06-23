#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> answer;
        unordered_map<string, vector<string>> mp;
        string temp;
        for (int i = 0; i < strs.size(); i++)
        {
            temp = strs[i];
            sort(temp.begin(), temp.end());
            mp[temp].push_back(strs[i]);
        }
        vector<string> tempAnswer;
        for (auto i = mp.begin(); i != mp.end(); i++)
        {
            tempAnswer = {};
            for (int j = 0; j < i->second.size(); j++)
            {
                tempAnswer.push_back(i->second[j]);
            }
            answer.push_back(tempAnswer);
        }
        return answer;
        
    }
};
