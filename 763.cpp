#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int lastIndex(char ch, string &s){
        int res;
        for (int i = 0; i < s.size(); i++)
        {
            if(s[i]==ch) res = i;
        }
        return res;
    }
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> res;
        int start = 0, end = 0;
        for (int i = 0; i < n; i++){
            start = i;
            end = lastIndex(s[i], s);
            if(end==i) {res.push_back(1); continue;}
            int j = i+1;
            while (j!=end){
                end = max(end, lastIndex(s[j], s));
                j++;
            }
            res.push_back(end-start+1);
            i = end;
        }
        return res;
    }
};