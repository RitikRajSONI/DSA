class Solution {
public:
    typedef pair<int,int> P;
    int networkDelayTime(vector<vector<int>>& times, int n, int src) {
        unordered_map<int, vector<P>> adj;
        for(auto &time:times){
            int u = time[0]-1;
            int v = time[1]-1;
            int t = time[2];
            adj[u].push_back({v,t});
        }

        vector<int> result(n,INT_MAX);
        priority_queue<P, vector<P>, greater<P> > pq;
        pq.push({0,src-1});
        result[src-1]=0;
        while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            for(auto &it:adj[node]){
                int adjnode=it.first;
                int dist=it.second;

                if( dist+d < result[adjnode]){
                    result[adjnode]=dist+d;
                    pq.push({result[adjnode], adjnode});
                }
            }
        }
        int mt=0;
        for(int i=0; i<n; i++){
            if(result[i]==INT_MAX) return -1;
            mt=max(mt,result[i]);
        }

        return mt;
    }
};