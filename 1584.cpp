class DisjointSet{
	public:
	vector<int> parent, size;
	
	DisjointSet(int n){
		parent.resize(n+1);
		size.resize(n+1, 1);
		for (int i = 0; i < n; i++){
			parent[i] = i;
		}
	}

	int findUlP(int u){
		if (u==parent[u]) return u;

		return parent[u] = findUlP(parent[u]);
	}

	void unionBySize(int u, int v){
		int ulp_u = findUlP(u);
		int ulp_v = findUlP(v);

		if (ulp_u==ulp_v) return;

		if (size[ulp_u]>=size[ulp_v]){
			size[ulp_u]+=size[ulp_v];
			parent[ulp_v] = ulp_u;
		}
		else{
			size[ulp_v]+=size[ulp_u];
			parent[ulp_u] = ulp_v;
		}
	}
};


class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
		vector<pair<int, pair<int, int>>> edges;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < i+1; j++){
				int wt = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
				edges.push_back({wt, {i, j}});
			}
		}
		sort(edges.begin(), edges.end());
		DisjointSet ds(n);
		int res = 0;
		for (auto it: edges){
			int wt = it.first;
			int u = it.second.first;
			int v = it.second.second;

			if (ds.findUlP(u)!=ds.findUlP(v)){
				res+=wt;
				ds.unionBySize(u, v);
			}
			
		}
		
		return res;
    }
};