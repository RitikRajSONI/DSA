class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        // C++ vector syntax initialization
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            // Using INT_MAX for infinity in C++
            int cost = INT_MAX;

            int j = i + 1;
            if (j <= n) {                                // jump of 1
                cost = dp[j] + costs[j - 1] + (j - i) * (j - i);
            }

            j = i + 2;                                  // jump of 2
            if (j <= n) {
                cost = min(cost, dp[j] + costs[j - 1] + (j - i) * (j - i));
            }

            j = i + 3;                                  // jump of 3
            if (j <= n) {
                cost = min(cost, dp[j] + costs[j - 1] + (j - i) * (j - i));
            }

            dp[i] = cost;
        }

        return dp[0];
    }
};


// class Solution {
// public:
//     int solve(int n, int i, vector<int>& costs, vector<int>& dp){
//         if (i > n) return 1e9;
//         if (i == n) return 0;
//         if (dp[i] != -1) return dp[i];
        
//         int c1 = solve(n, i + 1, costs, dp) + ((i < n) ? costs[i] : 0) + 1;
//         int c2 = solve(n, i + 2, costs, dp) + ((i + 1 < n) ? costs[i + 1] : 0) + 4;
//         int c3 = solve(n, i + 3, costs, dp) + ((i + 2 < n) ? costs[i + 2] : 0) + 9;

//         return dp[i] = min({c1, c2, c3});
//     }

//     int climbStairs(int n, vector<int>& costs) {
//         vector<int> dp(n + 1, -1);
//         dp[0]=0;
//         dp[1]=costs[0]+1;
//         for(int i=2; i<=n; i++){
            
//         }
//         return solve(n, 0, costs, dp);
//     }
// };
