class Solution {
public:
    typedef pair<int, int> P;

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<P>> adj(n);
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            int d = edge[2];
            
            adj[u].push_back({v, d});
            adj[v].push_back({u, d});
        }
        
        int res = -1, mincnt = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            priority_queue<P, vector<P>, greater<P>> pq;
            pq.push({0, i});
            
            vector<int> dists(n, INT_MAX);
            dists[i] = 0;
            
            while(!pq.empty()){
                auto [d, u] = pq.top(); pq.pop();
                if(d > dists[u]) continue;
                
                for (const auto& [v, weight] : adj[u]) {
                    if (dists[u] + weight < dists[v]) {
                        dists[v] = dists[u] + weight;
                        pq.push({dists[v], v});
                    }
                }
            }
            
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (dists[j] <= distanceThreshold) {
                    cnt++;
                }
            }
            
            if (cnt <= mincnt) {
                mincnt = cnt;
                res = i; 
            }
        }
        return res;
    }
};

// using Floyed Warshel :
// class Solution {
// public:
//     int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
//         vector<vector<int>> grid(n, vector<int>(n, 1e9));

//         for (int i = 0; i < n; i++) {
//             grid[i][i] = 0;
//         }


//         for(auto edge:edges){
//             int u=edge[0];
//             int v=edge[1];
//             int w=edge[2];
//             grid[u][v]=w;
//             grid[v][u]=w;
//         }
//         for (int via = 0; via < n; via++) {
//             for (int i = 0; i < n; i++) {
//                 for (int j = 0; j < n; j++) {
//                     // Only update if a valid path exists through the 'via' vertex
//                     if (grid[i][via] != 1e9 && grid[via][j] != 1e9) {
//                         grid[i][j] = min(grid[i][j], grid[i][via] + grid[via][j]);
//                     }
//                 }
//             }
//         }

//         int ans=-1,mincnt=1e9;
//         for(int i=0; i<n; i++){
//             int cnt = 0;
//             for(int j=0; j<n; j++){
//                 if(grid[i][j]<=distanceThreshold){
//                     cnt++;
//                 }
//             }
//             if(cnt <= mincnt){
//                 mincnt = cnt;
//                 ans = i;
//             }
//         }
//         return ans;
//     }
// };