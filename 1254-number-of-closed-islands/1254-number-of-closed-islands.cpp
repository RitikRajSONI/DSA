class Solution {
public:
    vector<vector<int>> dirs={{1,0},{0,1},{-1,0},{0,-1}};
    int m,n;
    void BFS(vector<vector<int>>& grid ,int i ,int j){
        grid[i][j]=1;
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
            auto [x,y]=q.front(); 
            q.pop();
            for(auto dir:dirs){
                int x_=x+dir[0];
                int y_=y+dir[1];
                if(x_>=0 && x_<m && y_>=0 && y_<n && grid[x_][y_]==0){
                    grid[x_][y_]=1;
                    q.push({x_,y_});
                }
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if( (i == 0 || i == m - 1 || j == 0 || j == n - 1) && grid[i][j]==0){
                    BFS(grid,i,j);
                }
            }
        }
        int cnt=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==0 ){
                    BFS(grid,i,j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};