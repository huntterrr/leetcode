class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges){
        if(n==1){
            return {0};
        }
        vector<vector<int>> adj(n);
        vector<int> indegree(n);
        for (int i = 0; i < n-1; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            indegree[u]++;
            indegree[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<int> q;
        vector<int> ans;
        for (int i = 0; i < n; i++){
            if (indegree[i]==1){
                q.push(i);
            }
        }
        while (!q.empty()){
            int s = q.size();
            ans = {};
            while (s--){
                int node = q.front();
                q.pop();
                ans.push_back(node);

                for(int adjNode: adj[node]){
                    indegree[adjNode]--;
                    if(indegree[adjNode]==1){
                        q.push(adjNode);
                    }
                }
            }
        }
        return ans;
    }
};