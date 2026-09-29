class Solution {
public:
    typedef pair<int,int> P;   // {w,x,y,idx}
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V=points.size();
        vector<vector<P>> adj(V);
        for(int i=0; i<V; i++){
            int x=points[i][0];
            int y=points[i][1];
            for(int j=i+1; j<V; j++){
                int x_=points[j][0];
                int y_=points[j][1];
                int dist=abs(x-x_)+abs(y-y_);
                adj[i].push_back({j,dist});
                adj[j].push_back({i,dist});
            }
        }
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<bool> inMST(V,false);
        pq.push({0,0});
        int sum=0;
        while(!pq.empty()){
            int w=pq.top().first;
            int n=pq.top().second;
            pq.pop();
            if(inMST[n]) continue;
            inMST[n]=true;
            sum+=w;
            for(auto& nbr:adj[n]){
                int nbrn=nbr.first;
                int nbrw=nbr.second;
                if(!inMST[nbrn]){
                    pq.push({nbrw,nbrn});
                }
            }
        }
        return sum;
    }
};