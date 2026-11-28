//
// These solutions are based on thing that suports insertion concepts :
//

// Bottom Up :
class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n));
        for(int i=0; i<n; i++) dp[i][i]=0;
        for(int L=2; L<=n; L++){
            for(int i=0; i+L-1<n; i++){
                int j = i+L-1;
                if(s[i]==s[j]){
                    dp[i][j] = dp[i+1][j-1];
                }else{
                    dp[i][j] = 1 + min(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0][n-1];
    }
};


// Recursion + Memoisation :
// class Solution {
// public:
//     int dp[501][501];
//     int solve(string& s, int i, int j){
//         if(i>=j) return 0;

//         if(dp[i][j]!=-1) return dp[i][j];
        
//         if(s[i]==s[j]){
//             return dp[i][j] = solve(s,i+1,j-1);
//         }
//         return dp[i][j] = 1 + min(solve(s,i+1,j), solve(s,i,j-1));
//     }
//     int minInsertions(string s) {
//         int n = s.size();
//         memset(dp,-1,sizeof(dp));
//         return solve(s,0,n-1);
//     }
// };


//.....................................................................................


//
// These solutions are from obeservation that 
// minInsertions = size(s) - LPS( solved in Leetcode -> 516)
//

// Bottom Up:
// class Solution {
// public:
//     int minInsertions(string s) {
//         int n = s.size();
//         vector<vector<int>> dp(n,vector<int>(n));
//         for(int i=0; i<n; i++) dp[i][i]=1;
//         for(int L=2; L<=n; L++){
//             for(int i=0; i+L-1<n; i++){
//                 int j = i+L-1;
//                 if(s[i]==s[j]){
//                     dp[i][j] = 2+dp[i+1][j-1];
//                 }else{
//                     dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
//                 }
//             }
//         }
//         return n - dp[0][n-1];
//     }
// };


// Recursion + Memoisation :
// class Solution {
// public:
//     int dp[501][501];
//     int solve(string& s, int i, int j){
//         if(i>j) return 0;
//         if(i==j) return 1;

//         if(dp[i][j]!=-1) return dp[i][j];
        
//         if(s[i]==s[j]){
//             return dp[i][j] = 2 + solve(s,i+1,j-1);
//         }
//         return dp[i][j] = max(solve(s,i+1,j), solve(s,i,j-1));
//     }
//     int minInsertions(string s) {
//         int n = s.size();
//         memset(dp,-1,sizeof(dp));
//         return n - solve(s,0,n-1);
//     }
// };