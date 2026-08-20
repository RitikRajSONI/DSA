class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> ar1;
        vector<int> ar2;
        ar1.push_back(nums[0]);
        ar2.push_back(nums[1]);
        for(int i=2; i<nums.size(); i++){
                if(ar1.back() > ar2.back()){
                    ar1.push_back(nums[i]);
                }
                else ar2.push_back(nums[i]);
        }

        vector<int> res;
        for(int i=0 ; i<ar1.size(); i++){
            res.push_back(ar1[i]);
        }
        for(int i=0 ; i<ar2.size(); i++){
            res.push_back(ar2[i]);
        }
        return res;
    }
};