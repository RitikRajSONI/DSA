class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> losses;
        unordered_set<int> players;
        
        // Record all players and count losses
        for (const auto& m : matches) {
            players.insert(m[0]);
            players.insert(m[1]);
            losses[m[1]]++;
        }
        
        vector<vector<int>> res(2);
        
        // Check loss counts for every unique player
        for (int p : players) {
            if (losses.find(p) == losses.end()) {
                res[0].push_back(p); // 0 losses
            } else if (losses[p] == 1) {
                res[1].push_back(p); // 1 loss
            }
        }
        
        // Sort the results
        sort(res[0].begin(), res[0].end());
        sort(res[1].begin(), res[1].end());
        
        return res;
    }
};
