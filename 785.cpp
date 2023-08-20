class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> visColor(graph.size(), -1);
        for (int i = 0; i < graph.size(); i++){
            if (visColor[i]==-1 and !dfs(graph, visColor, 0, i)){
                return false;
            }
        }
        return true;
    }
private:
    bool dfs(vector<vector<int>> &graph, vector<int> &visColor, int color, int start){
        visColor[start] = color;
        for (int i = 0; i < graph[start].size(); i++){

            if (visColor[graph[start][i]]==-1){
                if(!dfs(graph, visColor, 1-color, graph[start][i])){
                    return false;
                }
            }
            else if(visColor[start]==visColor[graph[start][i]]){
                return false;
            }
        }
        return true;
    }
};