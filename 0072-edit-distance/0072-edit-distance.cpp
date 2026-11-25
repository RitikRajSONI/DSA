// Bottom Up:
class Solution {
public:
    int minDistance(string w1, string w2) {
        int m=w1.size();
        int n=w2.size();
        vector<vector<int>> dp(m+1,vector<int> (n+1,0));
        for(int i=0; i<=m; i++){
            for(int j=0; j<=n; j++){
                if(i==0 || j==0){
                    dp[i][j]=i+j;
                }
                else if(w1[i-1] == w2[j-1]){
                    dp[i][j]= dp[i-1][j-1];
                }else{
                    dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                }
            }
        }
        return dp[m][n];
    }
};


// Recursion + Memoization :
// class Solution {
// public:
//     int m=0,n=0;
//     int dp[501][501];
//     int solve(string& w1, string& w2, int i, int j){
//         if(i>=m || j>=n){
//             return (m-i)+(n-j);
//         }
//         if(dp[i][j]!=-1) return dp[i][j];
        
//         if(w1[i]==w2[j]){
//             return solve(w1,w2,i+1,j+1);
//         }
//         int insert = 1 + solve(w1,w2,i,j+1);
//         int update = 1 + solve(w1,w2,i+1,j+1);
//         int Delete = 1 + solve(w1,w2,i+1,j);

//         return dp[i][j] = min({insert, update, Delete});
//     }
//     int minDistance(string w1, string w2) {
//         m=w1.size();
//         n=w2.size();
//         memset(dp,-1,sizeof(dp));
//         return solve(w1,w2,0,0);
//     }
// };