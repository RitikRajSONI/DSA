class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 1;
        int  mni=0,mxi=0;
        for(int i=1; i<n; i++){
            if(nums[mni]>nums[i]) mni=i; 
            if(nums[mxi]<nums[i]) mxi=i; 
        }
        int lo=min(mxi,mni);
        int hi=max(mni,mxi);

        int frontOnly = hi+1;
        int backOnly = n-lo;
        int split = (lo+1) + (n-hi);
        return min({frontOnly, backOnly, split});
    }
};