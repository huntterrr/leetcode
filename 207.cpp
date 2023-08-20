#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> vis(numCourses, 0);
        vector<int> Pathvis(numCourses, 0);
        for (vector<int> it: prerequisites)
        {
            int first = it[0];
            int second = it[1];
            adj[second].push_back(first);
        }

        for (int i = 0; i < numCourses; i++)
        {
            if (!vis[i])
            {
                if (!isCyclic(adj, vis, Pathvis, i))
                {
                    return false;
                }
            }
        }
        return true;
    }
private:
    bool isCyclic(vector<vector<int>> &adj, vector<int> &vis, vector<int> &pathVis, int start){
        vis[start] = 1;
        pathVis[start] = 1;

        for (int it: adj[start])
        {
            if (!vis[it])
            {
                if (!isCyclic(adj, vis, pathVis, it))
                {
                    return false;
                }
            }
            else if(pathVis[it]){
                return false;
            }
        }
        
        pathVis[start] = 0;
        return true;
    }
};