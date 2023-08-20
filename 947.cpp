#include<bits/stdc++.h>
using namespace std;

// class DisjointSet{
// public:
// 	vector<int> parent, rank, size;
// 	DisjointSet(int n){
// 		size.resize(n+1, 1);
// 		parent.resize(n+1);
// 		for (int i = 0; i <= n; i++)
// 		{
// 			parent[i] = i;
// 		}
// 	}

// 	int findUltParent(int node){
// 		if (node==parent[node]) return node;

// 		return parent[node] = findUltParent(parent[node]);
// 	}

// 	void unionBySize(int u, int v){
// 		int ulp_u = findUltParent(u);
// 		int ulp_v = findUltParent(v);
		
// 		if (ulp_u==ulp_v) return;
		
// 		if (size[ulp_u]>=size[ulp_v])
// 		{
// 			parent[ulp_v] = ulp_u;
// 			size[ulp_u] += size[ulp_v];
// 		}
// 		else{
// 			parent[ulp_u] = ulp_v;
// 			size[ulp_v] += size[ulp_u];
// 		}
// 	}
// };





class DisjointSet{
	public:
	vector<int> parent, size;
	DisjointSet(int n){
		size.resize(n+1, 1);
		parent.resize(n+1);
		for (int i = 0; i <= n; i++)
		{
			parent[i] = i;
		}
	}

	int findUlP(int node){
		if (parent[node]==node)
		{
			return node;
		}

		return parent[node] = findUlP(parent[node]);
	}

	void unionBySize(int u, int v){
		int ulp_u = findUlP(u);
		int ulp_v = findUlP(v);

		if (ulp_u==ulp_v){
			return;
		}
		if (size[ulp_u]>=size[ulp_v])
		{
			size[ulp_u]+=size[ulp_v];
			parent[ulp_v] = ulp_u;
		}else{
			size[ulp_v]+=size[ulp_u];
			parent[ulp_u] = ulp_v;
		}
	}
};


class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
    int maxRow = 0, maxColm = 0, n = stones.size();
		for (int i = 0; i < stones.size(); i++)
		{
			maxRow = max(maxRow, stones[i][0]);
			maxColm = max(maxColm, stones[i][1]);
		}

		DisjointSet ds(maxRow+maxColm+1);
		unordered_map<int, int> stonesMap;

		for (auto it: stones)
		{
			int u = it[0];
			int v = it[1]+maxRow+1;
			ds.unionBySize(u, v);
			stonesMap[u] = 1;
			stonesMap[v] = 1;
		}
		int cnt = 0;
		for (auto it: stonesMap)
		{
			if (it.first==ds.findUlP(it.first))
			{
				cnt++;
			}
		}
		
		return n-cnt;
		
		
    }
};