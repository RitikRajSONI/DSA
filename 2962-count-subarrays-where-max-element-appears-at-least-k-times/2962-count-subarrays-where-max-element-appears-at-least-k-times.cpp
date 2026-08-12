class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int mxe=*max_element(nums.begin(),nums.end());
        int n=nums.size();
        int l=0,r=0,mxc=0;
        long long res=0;
        while(r<n){
            if(nums[r]==mxe){
                mxc++;
            }

            while(mxc>=k){
                res+=n-r;
                if(nums[l]==mxe) mxc--;
                l++;
            }
            r++;
        }
        return res;
    }
};

/*
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int max_element=*max_element(nums.begin(),nums.end());
        vector<int> max_indices;
        int n=nums.size();
        long long res=0;
        for(int i=0; i<n; i++){
            if(nums[i]==max_element) max_indices.push_back(i);
            int size=max_indices.size();
            if(size>=k){
                int last_i = max_indices[size-k];
                res+=last_i+1;
            }
        }
        return res;
    }
};
*/