class Solution {
public:
    int n;
    typedef vector<vector<int>> vvi;
    void DFS(vvi& graph, int u, vector<int>& curpath, vvi& ans){
        curpath.push_back(u);
        if(u==n-1){
            ans.push_back(curpath);
            curpath.pop_back();
            return;
        }
        for(auto v:graph[u]){
            DFS(graph,v,curpath,ans);
        }
        curpath.pop_back();
    }
    vvi allPathsSourceTarget(vvi& graph) {
        vvi ans;
        n=graph.size();
        vector<int> curpath;
        DFS(graph,0,curpath,ans);
        return ans;
    }
};