class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;

        vector<long long> cnt(100001, 0);
        long long total = 0;
        for (int i = 0; i < n; i++) {
            int d = abs(nums1[i] - nums2[i]);
            cnt[d]++;
            total += d;
        }
        if (total <= k) return 0;

        // Push the plateau downward, from the largest value
        for (int v = 100000; v >= 1 && k > 0; v--) {
            if (cnt[v] == 0) continue;
            long long c = cnt[v];
            if (c <= k) {
                // lower all c elements from v to v-1
                cnt[v - 1] += c;
                cnt[v] = 0;
                k -= c;
            } else {
                // can only lower k of them
                cnt[v] -= k;
                cnt[v - 1] += k;
                k = 0;
            }
        }

        long long ans = 0;
        for (long long v = 1; v <= 100000; v++) {
            ans += cnt[v] * v * v;
        }
        return ans;
    }
};