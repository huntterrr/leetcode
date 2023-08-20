#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits==""){
            return res;
        }
        unordered_map<int, string> mp = {{2, "abc"},{3, "def"},{4, "ghi"},{5, "jkl"},{6, "mno"},{7, "pqrs"},{8, "tuv"},{9, "wxyz"}};
        string subset;
        dfs(mp, res, digits, subset, 0);
        return res;
    }
private:
    void dfs(unordered_map<int, string> &mp, vector<string>&res, string &digits, string subset, int start){
        if (start==digits.size())
        {
            res.push_back(subset);
            return;
        }
        int num = digits[start]-'0';
        for (char &c: mp[num])
        {
            dfs(mp, res, digits, subset+c, start+1);
        }
    }
};