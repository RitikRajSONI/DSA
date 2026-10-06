class Solution {
public:
    int n;
    int cu=2;
    vector<vector<int>> dirs={{0,-1},{-1,0},{0,1},{1,0}};
    int DFS(vector<vector<int>>& grid, int x, int y,vector<vector<bool>>& visited){
        if(x<0 || x>=n || y<0 || y>=n || visited[x][y] || grid[x][y]!=1) return 0;
        visited[x][y]=true;
        grid[x][y]=cu;
        int cnt=1;
        for(auto dir:dirs){
            int x_=x+dir[0];
            int y_=y+dir[1];
            cnt+=DFS(grid,x_,y_,visited);
        }
        return cnt;
    }
    int largestIsland(vector<vector<int>>& grid) {
        n=grid.size();
        unordered_map<int,int> mp;
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    int sz = DFS(grid,i,j,visited);
                    mp[cu]=sz;
                    ans = max(ans, sz);
                    cu++;
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==0){
                    unordered_set<int> seen;
                    int ms = 1;           // the flipped cell itself
                    for(auto& dir : dirs){
                        int i_ = i + dir[0];
                        int j_ = j + dir[1];
                        if(i_>=0 && i_<n && j_>=0 && j_<n){
                            int id = grid[i_][j_];
                            if(id >= 2 && !seen.count(id)){
                                seen.insert(id);
                                ms += mp[id];
                            }
                        }
                    }
                    ans = max(ans, ms);
                }
            }
        }

        return ans;
        

    }
};


// class Solution {
// public:
//     int n;
//     vector<vector<int>> dirs={{0,-1},{-1,0},{0,1},{1,0}};
//     int DFS(vector<vector<int>>& grid, int x, int y,vector<vector<bool>>& visited){
//         if(x<0 || x>=n || y<0 || y>=n || visited[x][y]){
//             return 0;
//         }
//         visited[x][y]=true;
//         int cnt=1;
//         for(auto dir:dirs){
//             int x_=x+dir[0];
//             int y_=y+dir[1];
//             cnt+=DFS(grid,x_,y_,visited);
//         }
//         return cnt;
//     }
//     int largestIsland(vector<vector<int>>& grid) {
//         int n=grid.size();
//         int mx=0;
//         vector<vector<bool>> visited(n,vector<bool>(n,false));
//         for(int i=0; i<n; i++){
//             for(int j=0; j<n; j++){
//                 if(grid[i][j]==1 && !visited[i][j]){
//                     mx=max(mx,DFS(grid,i,j,visited));
//                 }
//             }
//         }
//         for(int i=0; i<n; i++){
//             for(int j=0; j<n; j++){
//                 if(grid[i][j]==0){
//                     grid[i][j]=1;
//                     visited = vector<vector<bool>>(n,vector<bool>(n,false));
//                     mx=max(mx,DFS(grid,i,j,visited));
//                     grid[i][j]=0;
//                 }
//             }
//         }
//         return mx==0? n*n:mx;
//     }
    
// };