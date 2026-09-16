// we can apply here both Dijkastra as well as BFS(optimal for this question)
// because the weight of moving one to another cell is always one 

// remember the exapmle:
//  1->(2,1) ,(3,3)
//  2->(3,1)
// here bfs can consider shortest path 3 and mark 3 visited dont check for another route
// whereas Dijkastra check both of the case and use one with min weight  



class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]) return -1;

        queue<pair<int,int>> q;
        q.push({0,0});
        grid[0][0]=1;

        int pathLength=1;
        int drow[]={-1,-1,-1,0,0,1,1,1};
        int dcol[]={-1,0,1,-1,1,-1,0,1};

        while(!q.empty()){
            int s=q.size();
            while(s--){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();

                if(x == n-1 && y == n-1)
                    return pathLength;

                for(int i=0; i<8; i++){
                    int a=x+drow[i];
                    int b=y+dcol[i];
                    if(a>=0 && a<n && b>=0 && b<n && grid[a][b]==0){
                        q.push({a,b});
                        grid[a][b]=1;
                    }
                }
            }

            pathLength++;
        }
        return -1;
    }
};