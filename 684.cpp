#include<bits/stdc++.h>
using namespace std;

// Union by Size

class DisjointSet{
public:
	vector<int> parent, rank, size;
	DisjointSet(int n){
		size.resize(n+1, 1);
		parent.resize(n+1);
		for (int i = 0; i <= n; i++)
		{
			parent[i] = i;
		}
	}

	int findUltParent(int node){
		if (node==parent[node]) return node;

		return parent[node] = findUltParent(parent[node]);
	}

	void unionBySize(int u, int v){
		int ulp_u = findUltParent(u);
		int ulp_v = findUltParent(v);
		
		if (ulp_u==ulp_v) return;
		
		if (size[ulp_u]>size[ulp_v])
		{
			parent[ulp_v] = ulp_u;
			size[ulp_u] += size[ulp_v];
		}
		else{
			parent[ulp_u] = ulp_v;
			size[ulp_v] += size[ulp_u];
		}
	}
};


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int V = edges.size();
		DisjointSet ds(V);
		vector<vector<int>> res;
		for (int i = 0; i < V; i++)
		{
			int u = edges[i][0];
			int v = edges[i][1];
			if (ds.findUltParent(u)==ds.findUltParent(v))
			{
				res.push_back({u, v});
				continue;
			}
			ds.unionBySize(u, v);
		}

		return res[res.size()-1];	
    }
};