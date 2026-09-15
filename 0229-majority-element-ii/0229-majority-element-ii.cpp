class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> fq;
        for(int i=0; i<n; i++){
            fq[nums[i]]++;
        }
        vector<int> ans;
        for(auto [e,f]:fq){
            if(f>n/3) ans.push_back(e);
        }

        return ans;
    }
};