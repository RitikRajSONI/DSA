class Solution {
public:
    void dfs(vector<vector<int>> &isConnected, int u, vector<bool> &visited){
        int n=isConnected.size();
        visited[u]=true;
        for(int v=0; v<n; v++){
            if(isConnected[u][v]==1 && !visited[v])
                dfs(isConnected, v, visited);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<bool> visited(n,false);
        int cnt=0;
        for(int i=0; i<n; i++){
            if(!visited[i]) {
                dfs(isConnected, i, visited);
                cnt++;
            }
        }

        return cnt;
    }
};

// class Solution {
// public:
//     void dfs(unordered_map<int,vector<int>> &isConnected, int u, vector<bool> &visited){
//         visited[u]=true;
//         for(int &v:isConnected[u]){
//             if(!visited[v])
//                 dfs(isConnected, v, visited);
//         }
//     }
//     int findCircleNum(vector<vector<int>>& isConnected) {
//         int n=isConnected.size();
//         unordered_map<int,vector<int>> isConnected;
//         for(int i=0; i<n; i++){
//             for(int j=i+1; j<n; j++){
//                 if(isConnected[i][j]==1){
//                     isConnected[i].push_back(j);
//                     isConnected[j].push_back(i);
//                 }
//             }
//         }
//         vector<bool> visited(n,false);
//         int cnt=0;
//         for(int i=0; i<n; i++){
//             if(!visited[i]) {
//                 dfs(isConnected, i, visited);
//                 cnt++;
//             }
//         }

//         return cnt;
//     }
// };