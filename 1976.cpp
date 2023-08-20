class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        long long mod = 1e9+7;
        
        vector<vector<pair<long long, long long>>> adj(n);
        for (long long i = 0; i < roads.size(); i++)
        {
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        
        
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        pq.push({0, 0});
        
        
        vector<long long> dist(n, 1e18);
        dist[0] = 0;
        
        vector<long long> ways(n, 0);
        ways[0] = 1;
        
        while (!pq.empty())
        {
            long long node = pq.top().second;
            long long dis = pq.top().first;
            pq.pop();
            for (auto it: adj[node])
            {
                long long adjNode = it.first;
                long long cost = it.second;
                if (dist[adjNode]>dis+cost)
                {
                    dist[adjNode] = dis+cost;
                    ways[adjNode] = ways[node];
                    pq.push({dist[adjNode], adjNode});
                }
                else if(dist[adjNode]==dis+cost){
                    ways[adjNode] = (ways[adjNode]+ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};