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
    int largestIsland(vector<vector<int>>& grid) {
        vector<pair<int, int>> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
		int n = grid.size(), m = grid[0].size();
		DisjointSet ds(n*m);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (grid[i][j]==1){
					for (auto dir: dirs)
					{
						int newi = i+dir.first;
						int newj = j+dir.second;
						if (newi>=0 and newi<n and newj>=0 and newj<m and grid[newi][newj])
						{
							ds.unionBySize(m*i+j, m*newi+newj);
						}
					}
				}
			}
		}
		int res = *max_element(ds.size.begin(), ds.size.end()), temp;
		
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (!grid[i][j])
				{
					temp = 1;
					set<int> parentSet;
					for (auto dir: dirs)
					{
						int newi = i+dir.first;
						int newj = j+dir.second;
						if (newi>=0 and newi<n and newj>=0 and newj<m and grid[newi][newj])
						{
							// temp+=ds.size[ds.findUltParent(m*newi+newj)];
							parentSet.insert(ds.findUltParent(m*newi+newj));
						}
					}	
					for (int it:parentSet)
					{
						temp+=ds.size[it];
					}
					res = max(res, temp);
				}
			}
		}
		return res;
		
    }
};