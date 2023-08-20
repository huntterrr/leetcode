#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        vector<double> dist(n, INT_MIN);
        dist[start_node] = 1;
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node});
        while (!pq.empty())
        {
            auto itr = pq.top();
            pq.pop();
            int node = itr.second;
            double dis = itr.first;
            for (auto it: adj[node])
            {
                int adjNode = it.first;
                double cost = it.second;
                if (dist[adjNode]<cost*dis)
                {
                    dist[adjNode] = cost*dis;
                    pq.push({dist[adjNode], adjNode});
                }
            }
            
        }
        
        if(dist[end_node]==INT_MIN) return 0.00000;
        return dist[end_node];
        
    }
};