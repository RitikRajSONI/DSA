class Solution {
public:
    int m,n;
    void BFS(vector<vector<int>>& grid, int i, int j){
        int drow[]={1,0,-1,0};
        int dcol[]={0,1,0,-1};
        grid[i][j]=0;
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second; 
            q.pop();
            for (int k = 0; k < 4; k++) {
                int r_ = r + drow[k];
                int c_ = c + dcol[k];
                if (r_ >= 0 && r_ < m && c_ >= 0 && c_ < n && grid[r_][c_] == 1) {
                    q.push({r_, c_});
                    grid[r_][c_] = 0;
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        for(int i=0; i<m; i++){
            //j=0
            if(grid[i][0]==1){
                BFS(grid,i,0);
            }
            //j=n-1
            if(grid[i][n-1]==1){
                BFS(grid,i,n-1);
            }
        }
        for(int j=0; j<n; j++){
            //i=0
            if(grid[0][j]==1){
                BFS(grid,0,j);
            }
            //i=m-1
            if(grid[m-1][j]==1){
                BFS(grid,m-1,j);
            }
        }

        int ans=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1) ans++;
            }
        }

        return ans;
    }
};