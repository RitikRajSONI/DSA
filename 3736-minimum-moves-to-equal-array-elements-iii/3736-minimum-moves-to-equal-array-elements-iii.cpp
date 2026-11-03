class Solution {
public:
    int minMoves(vector<int>& nums) {
        int x = *max_element(nums.begin(),nums.end());
        int ans=0;
        for(int e:nums) 
            ans+=(x-e);
        
        return ans;
    }
};