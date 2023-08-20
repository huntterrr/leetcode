#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < times.size(); i++)
        {
            adj[times[i][0]-1].push_back({times[i][1]-1, times[i][2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k-1});
        
        vector<int> dist(n, INT_MAX);
        dist[k-1] = 0;

        while (!pq.empty())
        {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            for (auto &it: adj[node])
            {
                int adjNode = it.first;
                int cost = it.second;
                if (dist[adjNode]>dis+cost)
                {
                    dist[adjNode] = dis+cost;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        int res = -1;
        for (int i: dist){
            if (i==INT_MAX) return -1;
            res = max(res, i);
        }
        
        return res;
    }
};