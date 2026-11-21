// Bottom Up :
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> dp(n,1);
        vector<int> prev_i(n,-1);
        int mxl=1,mxi=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i]%nums[j]==0 && dp[j]+1 > dp[i]){
                    dp[i] = dp[j]+1;
                    prev_i[i]=j;
                }
            }
            if(mxl<dp[i]){
                mxl=dp[i];
                mxi=i;
            }
        }

        vector<int> ans;
        int ci=mxi;
        while(ci>=0){
            ans.push_back(nums[ci]);
            ci = prev_i[ci];
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};

// Memoisation can be done but it will also give TLE so use Bottom Up directly :
// Recursion :
// class Solution {
// public:
//     vector<int> solve(vector<int>& nums, int i, vector<int> ans){
//         if(i>=nums.size()) return ans;
//         //take:
//         vector<int> take = ans;
//         if(ans.size()==0 || nums[i]%ans.back()==0){
//             ans.push_back(nums[i]);
//             take = solve(nums,i+1,ans);
//             ans.pop_back();
//         }

//         vector<int> skip = solve(nums,i+1,ans);

//         return take.size()>=skip.size() ? take:skip;
//     }  
//     vector<int> largestDivisibleSubset(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         vector<int> ans;
//         return solve(nums,0,ans);
//     }
// };