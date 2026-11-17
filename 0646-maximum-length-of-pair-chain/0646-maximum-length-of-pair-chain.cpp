class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(), pairs.end());
        vector<int> dp(n,1);
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(pairs[j][1]<pairs[i][0]){
                    dp[i]=max(dp[j]+1,dp[i]);
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};


// class Solution {
// public:
//     vector<vector<int>> dp;
//     int solve(vector<vector<int>>& pairs, int i, int p){
//         if(i>=pairs.size()) return 0;
//         if(dp[i][p+1]!=-1) return dp[i][p+1];
//         //take 
//         int take=0,skip=0;
//         if(p==-1 || pairs[p][1]<pairs[i][0]){
//             take=1+solve(pairs,i+1,i);
//         }
//         //skip
//         skip=solve(pairs,i+1,p);
//         return dp[i][p+1]=max(take,skip);
//     }
//     int findLongestChain(vector<vector<int>>& pairs) {
//         int n=pairs.size();
//         sort(pairs.begin(), pairs.end());
//         dp.resize(n+1,vector<int>(n+1,-1));
//         return solve(pairs,0,-1);
//     }
// };