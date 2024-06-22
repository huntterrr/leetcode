class Solution {
public:
    int calc(string &s1, string &s2){
        int n1 = s1.length();
        int n2 = s2.length();

        for (int i = 0; i < n1; ++i) {
            if (s2.substr(0, n1 - i) == s1.substr(i)) {
                return n2 - (n1 - i);
            }
        }

        return n2;
    }
    string shortestSuperstring(vector<string>& words) {
        int n = words.size();
        vector<vector<pair<int, string>>> dp;
        vector<vector<int>> graph;
        dp.resize((1<<n), vector<pair<int, string>>(n, pair<int, string>(INT_MAX, "")));
        graph.resize(n, vector<int>(n));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                graph[i][j] = calc(words[i], words[j]);
                graph[j][i] = calc(words[j], words[i]);
            }
        }
        int resSize = INT_MAX;
        string resString = "";
        for(int mask = 0;mask<(1<<n);mask++){
            for(int i = 0;i<n;i++){
                if(mask&(1<<i)){
                    int premask = mask^(1<<i);
                    if(premask==0)
                        dp[mask][i] = {words[i].size(), words[i]};
                    else{
                        for(int k = 0; k < n; k++){
                            if(premask & (1 << k) && dp[premask][k].first+graph[k][i]<dp[mask][i].first){
                                if(dp[premask][k].first + graph[k][i] < dp[mask][i].first){
                                    dp[mask][i].first = dp[premask][k].first + graph[k][i];
                                    dp[mask][i].second = dp[premask][k].second + words[i].substr(words[i].size()-graph[k][i]);
                                }
                            }
                        }
                    }
                }
                if(mask==((1<<n)-1) and resSize>dp[mask][i].first){
                    resSize = dp[mask][i].first;
                    resString = dp[mask][i].second;
                }
            }
        }
        return resString;
    }
};