class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[j]<nums[i]){
                    dp[i]=max(dp[i],dp[j]+1);
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
//     int solve(vector<int>& nums, int i, int p){
//         if(i>=nums.size()) return 0;
//         if(dp[i][p+1]!=-1) return dp[i][p+1];
//         //take 
//         int take=0,skip=0;
//         if(p==-1 || nums[p]<nums[i]){
//             take=1+solve(nums,i+1,i);
//         }
//         //skip
//         skip=solve(nums,i+1,p);
//         return dp[i][p+1]=max(take,skip);
//     }
//     int lengthOfLIS(vector<int>& nums) {;
//         int n=nums.size();
//         dp.resize(n+1,vector<int>(n+1,-1));
//         return solve(nums,0,-1);
//     }
// };