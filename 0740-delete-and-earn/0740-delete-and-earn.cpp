class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n=0;
        for(int x:nums){
            n = max(n,x);
        }
        vector<int> arr(n+1,0);
        for(int x:nums){
            arr[x]+=x;
        }
        if(n==1) return arr[1];
        vector<int> dp(n+1);
        dp[0]=arr[0];
        dp[1]=max(dp[0],arr[1]);
        for(int i=2; i<=n; i++){
            dp[i]=max(dp[i-2]+arr[i],dp[i-1]);
        }
        return dp[n];
    }
};
// class Solution {
// public:
//     int deleteAndEarn(vector<int>& nums) {
//         unordered_map<int,int> mp;
//         for(int x:nums){
//             mp[x]++;
//         }
//         int ans=0;
//         while(mp.size()>0){
//             int mxa=0,mxe=-1;
//             for(auto [x,f]:mp){
//                 if(mxa<x*f){ 
//                     mxe=x;
//                     mxa=x*f;
//                 }
//             }
//             ans+=mxe*mp[mxe];
//             mp.erase(mxe);
//             auto it = mp.find(mxe-1);
//             if (it != mp.end()) {
//                 mp.erase(it);
//             }
//             it = mp.find(mxe+1);
//             if (it != mp.end()) {
//                 mp.erase(it);
//             }
//         }
//         return ans;
//     }
// };