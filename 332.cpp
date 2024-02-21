#include <bits/stdc++.h>
#pragma GCC optimize("03")
using namespace std;


class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
    vector<string> res;

    void dfs(string start){
        auto & edges = graph[start];
        while (!edges.empty()){
            string edge = edges.top();
            edges.pop();
            dfs(edge);
        }
        res.push_back(start);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto it: tickets){
            string u = it[0], v = it[1];
            graph[u].push(v);
        }
        dfs("JFK");
        reverse(res.begin(), res.end());
        return res;
    }
};