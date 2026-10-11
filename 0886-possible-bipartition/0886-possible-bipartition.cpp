class Solution {
public:
    bool checkBipartiteBFS(vector<vector<int>> &adj, int cur, vector<int> &color){
        color[cur]=1;
        queue<int> q;
        q.push(cur);
        while(!q.empty()){
            int u=q.front(); q.pop();
            for(auto v:adj[u]){
                if(color[v]==color[u]) return false;
                if(color[v]==-1) {
                    color[v]=1-color[u];
                    q.push(v);
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> color(n+1,-1);
        
        vector<vector<int>> adj(n+1);
        for(auto &edge:dislikes){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i=0; i<=n; i++){
            if(color[i]==-1){
                if(!checkBipartiteBFS(adj,i,color)) return false;
            }
        }
        return true;
    }
};