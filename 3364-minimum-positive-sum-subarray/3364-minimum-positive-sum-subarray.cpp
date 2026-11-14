class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int ans = INT_MAX;

        // Try every possible subarray length from l to r
        for (int sz = l; sz <= r; ++sz) {
            int csum = 0;
            // Compute sum of the first window of size 'sz'
            for (int i = 0; i < sz; ++i) {
                csum += nums[i];
            }
            if (csum > 0) {
                ans = min(ans, csum);
            }
            // Slide the window across the rest of the array
            for (int i = sz; i < n; ++i) {
                csum += nums[i] - nums[i - sz];
                if (csum > 0) {
                    ans = min(ans, csum);
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};


// class Solution {
// public:
//     int minimumSumSubarray(vector<int>& nums, int l, int r) {
//         int n=nums.size();
//         int ans=INT_MAX;
//         int csum=0;
//         int lp=0,rp=0;
//         while(rp<n){
//             csum+=nums[rp];
//             while(rp-lp>l && lp<=rp){
//                 csum-=nums[lp];
//                 lp++;
//             }
//             if(csum>0) ans=min(ans,csum);
//             rp++;
//         }
//         return ans==INT_MAX? -1:ans;
//     }
// };