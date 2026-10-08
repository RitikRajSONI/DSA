class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int s, int d) {
        if(s==d) return true;
        unordered_map<int,vector<int>> adj;
        for(auto e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        queue<int> q;
        vector<bool> visited(n,false);
        q.push(s);
        visited[s]=true;
        while(!q.empty()){
            int u=q.front(); q.pop();
            if(u==d) return true;
            for(auto v:adj[u]){
                if(visited[v]==false){
                    visited[v]=true;
                    q.push(v);
                }
            }
        }

        return false;
    }
};