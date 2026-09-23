class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> radj(n);
        vector<int> indeg(n,0);
        for(int u=0; u<n; u++){
            for(auto v:graph[u]){
                radj[v].push_back(u);
                indeg[u]++;
            }
        }

        queue<int> q;
        for(int i=0; i<n; i++){
            if(indeg[i]==0) q.push(i);
        }

        vector<int> safe;
        while(!q.empty()){
            int u = q.front(); q.pop();
            safe.push_back(u);
            for(auto v:radj[u]){
                indeg[v]--;
                if(indeg[v]==0) q.push(v);
            }
        }

        sort(safe.begin(),safe.end());
        return safe;
    }
};