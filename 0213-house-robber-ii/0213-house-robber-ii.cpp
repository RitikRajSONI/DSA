// Constant Space Bottom Up
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        // take 0:
        int prevprev=0;
        int prev=nums[0];
        int ans;
        for(int i=2; i<n; i++){
            int val=nums[i-1];
            ans=max(prev,val+prevprev);
            prevprev=prev;
            prev=ans;
        }
        int tz=ans;

        //don't take 0:
        prevprev=0;
        prev=0;
        for(int i=2; i<=n; i++){
            int val=nums[i-1];
            ans=max(prev,val+prevprev);
            prevprev=prev;
            prev=ans;
        }
        int dtz=ans;
        
        return max(tz,dtz);
    }
};

// O(n) Bottom Up:
// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         vector<int> t;
//         int n=nums.size();
//         if(n==1) return nums[0];
//         if(n==2) return max(nums[0],nums[1]);
//         // take 0:
//         t.assign(n+1,-1);
//         t[0]=0;
//         t[1]=nums[0];
//         for(int i=2; i<n; i++){
//             int val=nums[i-1];
//             t[i]=max(t[i-1],val+t[i-2]);
//         }
//         int tz=t[n-1];

//         //don't take 0:
//         t.assign(n+1,-1);
//         t[0]=0;
//         t[1]=0;
//         for(int i=2; i<=n; i++){
//             int val=nums[i-1];
//             t[i]=max(t[i-1],val+t[i-2]);
//         }
//         int dtz=t[n];
        
//         return max(tz,dtz);
//     }
// };


// Recursion + Memoization
// class Solution {
// public:
//     int t[101];
//     int n;
//     int solve(vector<int>& nums, int i, int z){
//         if(i>=z) return 0;
//         if(t[i]!=-1) return t[i];
//         int ch=nums[i]+solve(nums,i+2,z);
//         int nch=solve(nums,i+1,z);
//         return t[i]=max(ch,nch);
//     }
//     int rob(vector<int>& nums) {
//         n=nums.size();
//         if(n==1) return nums[0];
//         if(n==2) return max(nums[0],nums[1]);
//         memset(t,-1,sizeof(t));
//         int cz= solve(nums,0,n-1);
//         memset(t,-1,sizeof(t));
//         int ncz= solve(nums,1,n);
//         return max(cz,ncz);
//     }
// };