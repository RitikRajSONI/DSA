class Solution {
public:
     int m,n;
    void BFS(vector<vector<char>>& grid, int i1, int j1){
        queue<pair<int,int>> q;
        q.push({i1,j1});
        grid[i1][j1]='0';
        int drow[] = {-1,0,1,0};
        int dcol[] = {0,1,0,-1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second; q.pop();

            for(int i=0; i<4; i++){
                int nrow = r+drow[i];
                int ncol = c+dcol[i];

                if(nrow>=0 && nrow<m && ncol>=0 
                 && ncol<n && grid[nrow][ncol]=='1'){
                    q.push({nrow,ncol});
                    grid[nrow][ncol] = '0';
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;
        
        m=grid.size();
        n=grid[0].size();

        int ans=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]=='1'){
                    BFS(grid,i,j);
                    ans++;
                } 
            }
        }

        return ans;
    }
};