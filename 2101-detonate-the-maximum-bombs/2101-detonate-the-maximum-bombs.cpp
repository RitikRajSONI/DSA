class Solution {
public:
    typedef long long LL;
    void DFS(vector<vector<int>>& adj, int u, unordered_set<int>& visited){
        visited.insert(u);
        for(auto v:adj[u]){
            if(visited.find(v)==visited.end()){
                DFS(adj,v,visited);
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++){
            LL x1=bombs[i][0];
            LL y1=bombs[i][1];
            LL r1=bombs[i][2];
            for(int j=0; j<n; j++){
                if (i == j) continue;                
                LL x2 = bombs[j][0];
                LL y2 = bombs[j][1];
                
                LL distSq = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
                
                if(r1 * r1 >= distSq){
                    adj[i].push_back(j);
                }
            }
        }

        int ans=0;
        unordered_set<int> visited;
        for(int i=0; i<n; i++){
            DFS(adj,i,visited);
            int cnt=visited.size();
            ans=max(ans,cnt);
            visited.clear();
        }
        return ans;
    }
};


// class Solution {
// public:
//     typedef long long LL;
//     int DFS(vector<vector<int>>& adj, int u, vector<bool>& visited){
//         visited[u]=true;
//         int total=1;
//         for(auto v:adj[u]){
//             if(!visited[v]){
//                 total+=DFS(adj,v,visited);
//             }
//         }
//         return total;
//     }
//     int maximumDetonation(vector<vector<int>>& bombs) {
//         int n=bombs.size();
//         vector<vector<int>> adj(n);
//         for(int i=0; i<n; i++){
//             LL x1=bombs[i][0];
//             LL y1=bombs[i][1];
//             LL r1=bombs[i][2];
//             for(int j=0; j<n; j++){
//                 if (i == j) continue;                
//                 LL x2 = bombs[j][0];
//                 LL y2 = bombs[j][1];
                
//                 LL distSq = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
                
//                 if(r1 * r1 >= distSq){
//                     adj[i].push_back(j);
//                 }
//             }
//         }

//         int ans=0;
//         vector<bool> visited(n,false);
//         for(int i=0; i<n; i++){
//             int cnt=DFS(adj,i,visited);
//             ans=max(ans,cnt);
//             fill(visited.begin(), visited.end(), false);
//         }
//         return ans;
//     }
// };