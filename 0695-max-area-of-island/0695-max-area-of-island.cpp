class Solution {
public:
    vector<vector<int>> dirs = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    int m,n;
    int BFS(vector<vector<int>>& grid, int i, int j){
        queue<pair<int,int>> q;
        grid[i][j]=0;
        q.push({i,j});
        int area=0;
        while(!q.empty()){
            auto [x,y]=q.front(); q.pop();
            area++;
            for(auto& dir:dirs){
                int x_=x+dir[0];
                int y_=y+dir[1];
                if(x_>=0 && x_<m && y_>=0 && y_<n && grid[x_][y_]==1){
                    q.push({x_,y_});
                    grid[x_][y_]=0;
                }
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int maxArea=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    int area=BFS(grid,i,j);
                    maxArea=max(maxArea,area);
                }
            }
        }
        return maxArea;
    }
};