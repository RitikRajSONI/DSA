class Solution {
public:
    int digitSum(int x) {
        int s = 0;
        while (x > 0) {
            s += x % 10;
            x /= 10;
        }
        return s;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        // Step 1: make a sorted copy (by digit sum, then by value)
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end(), [&](int a, int b) {
            int da = digitSum(a), db = digitSum(b);
            if (da != db) return da < db;
            return a < b;
        });

        // Step 2: remember where each number should end up
        unordered_map<int, int> targetPos;
        for (int i = 0; i < n; i++) {
            targetPos[sorted[i]] = i;
        }

        // Step 3: count swaps by walking through cycles
        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;

            int cycleLength = 0;
            int j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = targetPos[nums[j]];  // jump to where nums[j] belongs
                cycleLength++;
            }

            swaps += cycleLength - 1;
        }

        return swaps;
    }
};