class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if (n == 0) return 0; 
        vector<int> t(n+1);
        t[0]=0;
        t[1]=nums[0];
        for(int i=2; i<=n; i++){
            int val=nums[i-1];
            t[i]=max(t[i-1],val+t[i-2]);
        }
        return t[n];
    }
};



// class Solution {
// public:
//     vector<int> t;
//     int solve(int i, vector<int>& nums){
//         if(i>=nums.size()) return 0;
//         // choosed
//         if(t[i]!=-1) return t[i];
//         int ch = nums[i] + solve(i+2,nums);
//         int nch=solve(i+1,nums);
//         return t[i]=max(ch,nch);
//     }
//     int rob(vector<int>& nums) {
//         int n=nums.size();
//         t.resize(n+1,-1);
//         return solve(0,nums);
//     }
// };

// Totaly Wrong Approach ex - [3,1,2,7,1] ans=10 not 8;
// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n=nums.size();
//         if(n==1) return nums[0];
//         int s1=0,s2=0;
//         // for even indxs:
//         for(int i=0; i<n; i+=2){
//             s1+=nums[i];
//         }
//         // for odd indxs:
//         for(int i=1; i<n; i+=2){
//             s2+=nums[i];
//         }

//         return max(s1,s2);
//     }
// };