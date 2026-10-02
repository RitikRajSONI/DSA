// Using Krushkal's Method:
class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if(parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);


        if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if(rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }

    int Krushkal(vector<vector<int>>& edges){
        int sum=0;
        for(auto temp:edges){
            int u=temp[0];
            int v=temp[1];
            int w=temp[2];
            if(find(u)!=find(v)){
                sum+=w;
                Union(u,v);
            }
        }
        return sum;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        parent.resize(V);
        rank.resize(V,0);
        for(int i=0; i<V; i++)
            parent[i]=i;
        
        vector<vector<int>> edges;
        for(int i=0; i<V; i++){
            for(int j=i+1; j<V; j++){
                int x=points[i][0],  y=points[i][1];
                int x_=points[j][0], y_=points[j][1];
                int dist=abs(x-x_)+abs(y-y_);
                edges.push_back({i,j,dist});
            }
        }
        auto comparator=[&](vector<int>& v1,vector<int>& v2){
            return v1[2]<v2[2];
        };
        sort(edges.begin(),edges.end(),comparator);
        return Krushkal(edges);
    }
};

// Using Prim's Algorithm :

// class Solution {
// public:
//     typedef pair<int,int> P;
//     int minCostConnectPoints(vector<vector<int>>& points) {
//         int V=points.size();
//         vector<vector<P>> adj(V);
//         for(int i=0; i<V; i++){
//             int x=points[i][0];
//             int y=points[i][1];
//             for(int j=i+1; j<V; j++){
//                 int x_=points[j][0];
//                 int y_=points[j][1];
//                 int dist=abs(x-x_)+abs(y-y_);
//                 adj[i].push_back({j,dist});
//                 adj[j].push_back({i,dist});
//             }
//         }
//         priority_queue<P, vector<P>, greater<P>> pq;
//         vector<bool> inMST(V,false);
//         pq.push({0,0});
//         int sum=0;
//         while(!pq.empty()){
//             int w=pq.top().first;
//             int n=pq.top().second;
//             pq.pop();
//             if(inMST[n]) continue;
//             inMST[n]=true;
//             sum+=w;
//             for(auto& nbr:adj[n]){
//                 int nbrn=nbr.first;
//                 int nbrw=nbr.second;
//                 if(!inMST[nbrn]){
//                     pq.push({nbrw,nbrn});
//                 }
//             }
//         }
//         return sum;
//     }
// };