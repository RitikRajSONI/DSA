class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total_sum = 0;
        for (int num : nums) total_sum += num;
        
        // If the target is exactly the total sum, we must remove all elements
        int target = total_sum - x;
        if (target == 0) return nums.size();
        if (target < 0) return -1;
        
        int max_len = -1;
        int current_sum = 0;
        int l = 0;
        
        // Find the longest subarray that sums to 'target'
        for (int r = 0; r < nums.size(); r++) {
            current_sum += nums[r];
            
            while (current_sum > target && l <= r) {
                current_sum -= nums[l];
                l++;
            }
            
            if (current_sum == target) {
                max_len = max(max_len, r - l + 1);
            }
        }
        
        // If we found a valid middle subarray, the operations needed 
        // are the remaining elements outside of it.
        return (max_len == -1) ? -1 : nums.size() - max_len;
    }
};
