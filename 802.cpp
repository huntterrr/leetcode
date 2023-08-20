//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;




class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0), pathVis(n, 0), check(n, 0), safeNodes;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(graph, vis, pathVis, check, i);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (check[i])
            {
                safeNodes.push_back(i);
            }
        }
        
        return safeNodes;
    }
private:
    bool dfs(vector<vector<int>> &graph, vector<int> &vis, vector<int> &pathVis, vector<int> &check, int start){
        vis[start] = 1;
        pathVis[start] = 1;
        check[start] = 1;
        for (int i: graph[start])
        {
            if (!vis[i])
            {
                if (dfs(graph, vis, pathVis, check, i))
                {
                    check[start] = 0;
                    return true;
                }
            }
            else if(pathVis[i]){
                check[start] = 0;
                return true;
            }
        }
        pathVis[start] = 0;
        check[start] = 1;
        return false;
    }
};
