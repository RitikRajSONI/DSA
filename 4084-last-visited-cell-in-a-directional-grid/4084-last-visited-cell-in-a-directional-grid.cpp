#include <vector>
using namespace std;

class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int r = 0, c = 0;
        visited[r][c] = true;

        while (true) {
            int nr = r, nc = c;
            switch (grid[r][c]) {
                case 'L': nc--; break;
                case 'R': nc++; break;
                case 'U': nr--; break;
                case 'D': nr++; break;
            }

            // Out of bounds or already visited: the move is not made
            if (nr < 0 || nr >= m || nc < 0 || nc >= n || visited[nr][nc]) {
                return {r, c};
            }

            r = nr;
            c = nc;
            visited[r][c] = true;
        }
    }
};