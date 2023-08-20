#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> vec;
        vector<string> subset;
        dfs(vec, s,  subset, 0);
        return vec;
    }
private:
    void dfs(vector<vector<string>> &res, string &s, vector<string> subset, int start){
        if (start==s.length())
        {
            res.push_back(subset);
            return;
        }
        for (int i = start; i < s.length(); i++)
        {
            if (isPolindrom(s.substr(start, i-start+1)))
            {
                subset.push_back(s.substr(start, i-start+1));
                dfs(res, s, subset, i+1);
                subset.pop_back();
            }
        }
    }
    bool isPolindrom(string s){
        int left = 0, right = s.size()-1;
        while (left<=right)
        {
            if (s[left]!=s[right])
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};