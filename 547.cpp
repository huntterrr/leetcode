//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (isConnected[i][j]==1 and i!=j)
                {
                    adj[i].push_back(j);
                }
            }
        }
        vector<int> visited(n, 0);
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(i, adj, visited);
                cnt++;
            }
            
        }
        return cnt;
    }
private:
    void dfs(int start, vector<int> adj[], vector<int> &visited){
        visited[start] = 1;
        for(auto it: adj[start]){
            if (!visited[it])
            {
                dfs(it, adj, visited);
            }
        }
    }
};