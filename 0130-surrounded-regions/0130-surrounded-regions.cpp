class Solution {
public:
    int m,n;
    static constexpr int drow[] = {0, 0, 1, -1};
    static constexpr int dcol[] = {1, -1, 0, 0};
    void BFS(vector<vector<char>>& board,int i, int j){
        board[i][j]='V';
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int k=0; k<4; k++){
                int r_ = r+drow[k];
                int c_ = c+dcol[k];
                if(r_>=0 && r_<m && c_>=0 && c_<n && board[r_][c_]=='O'){
                    board[r_][c_]='V';
                    q.push({r_,c_});
                }
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return; // Edge case safety
        m=board.size();
        n=board[0].size();
        for(int i=0; i<m; i++){
            if(board[i][0]=='O'){
                BFS(board,i,0);
            }
            if(board[i][n-1]=='O'){
                BFS(board,i,n-1);
            }
        }

        for(int j=0; j<n; j++){
            if(board[0][j]=='O'){
                BFS(board,0,j);
            }
            if(board[m-1][j]=='O'){
                BFS(board,m-1,j);
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]=='V'){
                    board[i][j]='O';
                }else{
                    board[i][j]='X';
                }
            }
        }
    }
};