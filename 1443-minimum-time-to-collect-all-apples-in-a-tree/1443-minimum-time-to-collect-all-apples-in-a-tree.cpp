class Solution {
public:
    int DFS(vector<vector<int>>& adj, int cur, int parent, vector<bool>& hasApple){
        int time=0;
        for(auto child:adj[cur]){
            if(child==parent) continue;
            int tfc=DFS(adj,child,cur,hasApple);
            if(tfc>0 || hasApple[child]){
                time+=(tfc+2);
            }
        }
        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return DFS(adj,0,-1,hasApple);
    }
};