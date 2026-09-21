class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor=image[sr][sc];
        if (iniColor == color) return image;

        int m=image.size();
        int n=image[0].size();

        queue<pair<int,int>> q;
        q.push({sr,sc});
        image[sr][sc]=color;

        int drow[] = {0, 0, 1, -1};
        int dcol[] = {1, -1, 0, 0};

        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int r_=drow[i]+r;
                int c_=dcol[i]+c;
                if(r_ >= 0 && c_ >= 0 && r_ < m && c_ < n && image[r_][c_] == iniColor){
                    q.push({r_, c_});
                    image[r_][c_] = color;
                }
            }
        }

        return image;
    }
};