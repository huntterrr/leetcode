//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < flights.size(); i++)
        {
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        // {stops, {node, cost}}
        queue<pair<int, pair<int, int>>> q;
        vector<int> dist(n, 1e9);
        q.push({k, {src, 0}});
        dist[src] = 0;
        while (!q.empty())
        {
            int stops = q.front().first;
            int node = q.front().second.first;
            int dis = q.front().second.second;
            q.pop();
            if (stops>=0)
            {
                for (auto &it: adj[node])
                {
                    int adjNode = it.first;
                    int cost = it.second;
                    if (cost+dis<dist[adjNode])
                    {
                        dist[adjNode] = cost+dis;
                        q.push({stops-1, {adjNode, dist[adjNode]}});
                    }       
                }
            }
        }
        if(dist[dst]==1e9) return -1;
        return dist[dst];

    }
};