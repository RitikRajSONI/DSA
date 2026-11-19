//
class Solution {
public:
    long long maxBalancedSubsequenceSum(vector<int>& nums) {
        int mxe=*max_element(nums.begin(),nums.end());
        if(mxe<=0) return mxe;

        int n=nums.size();
        map<int,long long> mp;

        long long maxSum=INT_MIN;

        for(int i=0; i<n; i++){
            auto it = mp.upper_bound(nums[i]-i);
            long long sum=nums[i];
            if(it!=mp.begin()){
                it--;
                sum+=it->second;
            }

            mp[nums[i]-i] = max(mp[nums[i]-i],sum);
            it = mp.upper_bound(nums[i]-i);
            while(it!=mp.end() && it->second <=sum){
                mp.erase(it++);
            }

            maxSum=max<long long>(maxSum,sum);
        }
        return maxSum;
    }
};

// Bottom Up : 
// class Solution {
// public:
//     long long maxBalancedSubsequenceSum(vector<int>& nums) {
//         int mxe=*max_element(nums.begin(),nums.end());
//         if(mxe<=0) return mxe;
//         int n=nums.size();
//         vector<long long> dp(n);
//         for(int i=0; i<n; i++) dp[i]=nums[i];

//         long long maxSum=INT_MIN;
//         for(int i=0; i<n; i++){
//             for(int j=0; j<i; j++){
//                 if(nums[i]-i >= nums[j]-j){
//                     dp[i] = max<long long>(dp[i],dp[j]+nums[i]);
//                     maxSum = max(dp[i],maxSum);
//                 }
//             }
//         }
//         return maxSum;
//     }
// };


// Recursion + Memoisation :
// class Solution {
// public:
//     unordered_map<string,long long> mp;
//     long long solve(vector<int>& nums, int i, int p){
//         if(i>=nums.size()) return 0;
//         string key=to_string(i)+"_"+to_string(p);
//         if(mp.find(key)!=mp.end()) return mp[key];
//         long long take=INT_MIN;
//         long long skip=INT_MIN;

//         //take
//         // if(p==-1 || nums[i]-nums[p]>=i-p){  OR
//         if(p==-1 || nums[i]-i>=nums[p]-p){
//             take = nums[i]+solve(nums,i+1,i);
//         }

//         //skip
//         skip=solve(nums,i+1,p);

//         return mp[key] = max<long long>(take,skip);
//     }
//     long long maxBalancedSubsequenceSum(vector<int>& nums) {
//         int mxe=*max_element(nums.begin(),nums.end());
//         if(mxe<=0) return mxe;
//         return solve(nums,0,-1);
//     }
// };