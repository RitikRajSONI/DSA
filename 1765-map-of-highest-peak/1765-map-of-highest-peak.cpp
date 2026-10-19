class Solution {
public:
    vector<vector<int>> dirs = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m=isWater.size();
        int n=isWater[0].size();
        // vector<vector<int>> ans(m,vector<int>(n,-1));
        queue<pair<int,int>> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(isWater[i][j]==1){
                    q.push({i,j});
                    isWater[i][j]=0;
                }else isWater[i][j]=-1;
            }
        }
        int h=1;
        while(!q.empty()){
            int sz=q.size();
            for(int k=0; k<sz; k++){
                auto [x,y]=q.front(); q.pop();
                for(auto dir:dirs){
                    int x_=x+dir[0];
                    int y_=y+dir[1];
                    if(x_>=0 && x_<m && y_>=0 && y_<n && isWater[x_][y_]==-1){
                        isWater[x_][y_]=h;
                        q.push({x_,y_});
                    }
                }
            }
            h++;
        }

        return isWater;
    }
};