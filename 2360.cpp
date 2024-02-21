#include <bits/stdc++.h>
using namespace std;
#define vc vector

class Solution {
public:
    vc<int> vis, pathVis, dist;
    void dfs(int node, int distance, vc<int>&edges, int &ans){
        if(node!=-1){
            if(!vis[node]){
               vis[node] = 1;
               pathVis[node] = 1;
               dist[node] = distance;
               dfs(edges[node], distance+1, edges, ans);
            }
            else if(pathVis[node]){
                ans = max(ans, distance-dist[node]);
            }
            pathVis[node] = 0;
        }
    }

    int longestCycle(vector<int>& edges) {
        int V = edges.size(), ans = -1;
        vis.resize(V, 0); pathVis.resize(V, 0); dist.resize(V, 0);
        for (int node = 0; node < V; node++){
            if(!vis[node]){
                dfs(node, 0, edges, ans);
            }
        }
        return ans;
    }
};