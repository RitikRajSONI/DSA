class Solution {
public:
    vector<vector<int>> directions = {{-1,0},{0,-1},{1,0},{0,1}};
    typedef pair<int,pair<int,int>> P;
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> res(m,vector<int>(n,INT_MAX));
        priority_queue<P, vector<P>, greater<P>> pq;

        auto isSafe = [&](int x, int y){
            return x>=0 && x<m && y>=0 && y<n;
        };

        res[0][0]=0;
        pq.push({0,{0,0}});

        while(!pq.empty()){
            int diff = pq.top().first;
            auto cdns= pq.top().second; 
            pq.pop();
            int x = cdns.first;
            int y = cdns.second;
            if(x==m-1 && y==n-1) return diff;
            for(auto dir:directions){
                int x_=x+dir[0];
                int y_=y+dir[1];
                if(isSafe(x_,y_)){
                    int absdiff=abs(heights[x][y] - heights[x_][y_]);
                    int maxdiff = max(absdiff,diff);
                    if(res[x_][y_]>maxdiff){
                        res[x_][y_]=maxdiff;
                        pq.push({maxdiff,{x_,y_}});
                    }
                }
            }
        }
        return res[m-1][n-1];
    }
};