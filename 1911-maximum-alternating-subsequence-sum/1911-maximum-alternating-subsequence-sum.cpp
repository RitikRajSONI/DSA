class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> t(n+1,vector<long long>(2,0));
        for(int i=1; i<=n; i++){
            t[i][0] = max(t[i-1][1]-nums[i-1] , t[i-1][0]);
            t[i][1] = max(t[i-1][0]+nums[i-1] , t[i-1][1]);
        }

        return max(t[n][0],t[n][1]);
    }
};
// class Solution {
// public:
//     // t[i][0] will store the result for isEven = false (odd indexed element in the alternating subsequence)
//     // t[i][1] will store the result for isEven = true (even indexed element in the alternating subsequence)
//     vector<vector<long long>> t; 

//     long long solve(vector<int>& nums, int i, bool isEven) {
//         if (i >= nums.size()) return 0;
//         // Check if this specific state (index i AND parity isEven) has already been computed
//         if (t[i][isEven] != -1) return t[i][isEven];
        
//         // Option 1: Skip the current element
//         long long skip = solve(nums, i + 1, isEven);
        
//         // Option 2: Take the current element
//         long long val = isEven ? nums[i] : -nums[i];
//         long long take = val + solve(nums, i + 1, !isEven);
        
//         // Cache and return the result for this specific state
//         return t[i][isEven] = max(take, skip);
//     }

//     long long maxAlternatingSum(vector<int>& nums) {
//         int n = nums.size();
//         t.assign(n, vector<long long>(2, -1));
//         return solve(nums, 0, true);
//     }
// };



// class Solution {
// public:
//     long long solve( vector<int>& nums, int i, bool isEven){
//         if(i>=nums.size()) return 0;
//             // Option 1: Skip the current element
//             long long skip = solve(nums, i + 1, isEven);
            
//             // Option 2: Take the current element
//             long long val = isEven ? nums[i] : -nums[i];
//             long long take = val + solve(nums, i + 1, !isEven);
//         return max(take,skip);
//     }
//     long long maxAlternatingSum(vector<int>& nums) {
//         int n=nums.size();
//         return solve(nums,0,true);
//     }
// };