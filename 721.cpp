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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
		DisjointSet ds(n);
		unordered_map<string, int> mailNode;
		for (int i = 0; i < n; i++)
		{
			for (int j = 1; j < accounts[i].size(); j++)
			{
				string mail = accounts[i][j];
				if (mailNode.find(mail)==mailNode.end()){
					mailNode[mail] = i;
				}else{
					ds.unionBySize(mailNode[mail] ,i);
				}
			}
		}

		vector<vector<string>> mergeMail(n);
		for (auto it: mailNode){
			mergeMail[ds.findUltParent(it.second)].push_back(it.first);
		}

		vector<vector<string>> res;
		for (int i = 0; i < n; i++)
		{
			if (mergeMail[i].size()==0) continue;
			sort(mergeMail[i].begin(), mergeMail[i].end());
			vector<string> temp;
			temp.push_back(accounts[i][0]);
			for (auto it: mergeMail[i]){
				temp.push_back(it);
			}
			res.push_back(temp);
		}
		
		return res; 

		
		
    }
};