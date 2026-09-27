class Solution {
public:
    typedef pair<long long, int> P;
    int M = 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int, long long>>> adj;
        for(auto road:roads){
            int u = road[0];
            int v = road[1];
            long long t = road[2];
            adj[u].push_back({v,t});
            adj[v].push_back({u,t});
        }

        vector<long long> res(n,LLONG_MAX);
        vector<long long> cntw(n,0);
        res[0]=0;
        cntw[0]=1;
        priority_queue<P , vector<P>, greater<P>> pq;
        pq.push({0,0});
        int cp=0;
        while(!pq.empty()){
            long long d = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            if (d > res[u]) continue;
            for(auto pr:adj[u]){
                int v=pr.first;
                int dist=pr.second;
                if(d+dist < res[v]){
                    res[v]=d+dist;
                    pq.push({res[v],v});
                    cntw[v]=cntw[u];
                }else if(d+dist == res[v]){
                    cntw[v]=(cntw[v]+cntw[u])%M ;
                }
            }
        }

        return cntw[n-1]; 
    } 
};