class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        // Initialize the result matrix with -1 to track unvisited cells
        vector<vector<int>> res(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        
        // Step 1: Add all '0's to the queue and set their distance to 0
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    res[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        // Direction arrays for moving up, down, left, right
        int drow[] = {0, 0, 1, -1};
        int dcol[] = {1, -1, 0, 0};
        
        // Step 2: Multi-source BFS
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            
            for (int k = 0; k < 4; k++) {
                int r_ = r + drow[k];
                int c_ = c + dcol[k];
                
                // If the neighbor is valid and has not been visited yet
                if (r_ >= 0 && r_ < m && c_ >= 0 && c_ < n && res[r_][c_] == -1) {
                    res[r_][c_] = res[r][c] + 1; // Shortest distance found
                    q.push({r_, c_});
                }
            }
        }
        
        return res;
    }
};
