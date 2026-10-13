class Solution {
public:
    void DFS(vector<vector<int>>& adj, int u, int p, vector<int>& ans,const string& labels , int counts[26]){
        int lblidx=labels[u]-'a';
        int cntBefore=counts[lblidx];
        counts[lblidx]++;
        for(auto v:adj[u]){
            if(v==p) continue;
            DFS(adj,v,u,ans,labels,counts);
        }
        ans[u]=counts[lblidx]-cntBefore;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> ans(n,0);
        int counts[26] = {0};
        DFS(adj,0,-1,ans,labels,counts);
        return ans;
    }
};