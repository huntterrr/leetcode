/*
	Author: Haciyev Huseyn
*/
#include <bits/stdc++.h>
using namespace std;
int n;
vector<string> words; 
vector<vector<pair<int, string>>> dp;
vector<vector<int>> graph;

class Solution {
public:
    bool isPossible(int n, vector<vector<int>>& edges) {
        bool flag = 0;
        vector<int> degree(n+1);
        set<pair<int, int>> st;
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            st.insert({u, v});
            st.insert({v, u});
            degree[u]++;
            degree[v]++;
        }
        vector<int> odd;
        for(int i = 1;i<=n;i++) if(degree[i]&1) odd.push_back(i);
        int cnt = odd.size();
        if(cnt&1 or cnt>4) return 0;
        if(cnt==0) return 1;
        int a = odd[0], b = odd[1];
        if(cnt==2){
            if(!st.count({a, b})) return 1;
            else{
                for(int i = 1;i<=n;i++){
                    if(!st.count({a, i}) and !st.count({b, i})){
                        return 1;
                    }
                }
            }
        }
        if(cnt==4){
            int c = odd[2], d = odd[3];
            if(!st.count({a, b}) and !st.count({c, d}) or
               !st.count({a, c}) and !st.count({b, d}) or 
               !st.count({a, d}) and !st.count({b, c})) return 1;
        }
        return 0;
    }
};