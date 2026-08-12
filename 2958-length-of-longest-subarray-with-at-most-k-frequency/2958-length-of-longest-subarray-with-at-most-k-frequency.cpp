class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> frequency;
        int l=0,max_length=0;
        int culprit=0;
        for(int r=0; r<nums.size(); r++){
            if(++frequency[nums[r]] == k+1){
                culprit++;
            }
            if(culprit > 0){
                frequency[nums[l]]--;
                if(frequency[nums[l]]==k) culprit--;
                l++;
            }
            if(culprit==0) max_length=max(max_length,r-l+1);
        }
        return max_length;
    }
};

/*
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> frequency;
        int l=0,max_length=0;
        for(int r=0; r<nums.size(); r++){
            frequency[nums[r]]++;
            while(l<r && frequency[nums[r]]>k){
                frequency[nums[l]]--;
                l++;
            }
            max_length=max(max_length,r-l+1);
        }
        return max_length;
    }
}
*/