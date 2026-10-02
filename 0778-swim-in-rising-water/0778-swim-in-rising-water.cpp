class Solution {
public:
    static constexpr int drow[] = {0,0,1,-1};
    static constexpr int dcol[] = {1,-1,0,0};
    typedef pair<int,pair<int,int>> P;
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({grid[0][0],{0,0}});
        visited[0][0]=true;
        int ans=INT_MAX;
        while(!pq.empty()){
            int w=pq.top().first;
            auto cd=pq.top().second;
            pq.pop();
            int r=cd.first;
            int c=cd.second;
            if(r==n-1 && c==n-1) return w;
            for(int i=0; i<4; i++){
                int r_=r+drow[i];
                int c_=c+dcol[i];

                if(r_>=0 && r_<n && c_>=0 && c_<n && visited[r_][c_]==false){
                    visited[r_][c_]=true;
                    pq.push({max(w,grid[r_][c_]), { r_, c_}});
                }
            }
        }
        return -1; 
    }
};