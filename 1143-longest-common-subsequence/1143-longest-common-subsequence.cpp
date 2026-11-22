// Bottom Up :
class Solution {
public:
    int longestCommonSubsequence(string t1, string t2) {
        int m=t1.size(),n=t2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(t1[i-1]==t2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};


// Recursion + Memoisation :
// class Solution {
// public:
//     int dp[1001][1001];

//     int solve(const string& text1, const string& text2, int i, int j) {
//         if (i >= (int)text1.size() || j >= (int)text2.size()) return 0;
//         if (dp[i][j] != -1) return dp[i][j];

//         int match = 0, skip1 = 0, skip2 = 0;
//         if (text1[i] == text2[j]) {
//             match = 1 + solve(text1, text2, i + 1, j + 1);
//         } else {
//             skip1 = solve(text1, text2, i, j + 1);
//             skip2 = solve(text1, text2, i + 1, j);
//         }

//         return dp[i][j] = max({match, skip1, skip2});
//     }

//     int longestCommonSubsequence(string text1, string text2) {
//         memset(dp, -1, sizeof(dp));
//         return solve(text1, text2, 0, 0);
//     }
// };
