class Solution {
public:
    typedef pair<int,int> P;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int MOD = 1e9 + 7;
        priority_queue<P, vector<P>, greater<P>> pq;

        for (int i = 0; i < n; ++i) {
            pq.push({nums[i], i});
        }

        long long res = 0;
        for (int k = 1; k <= right; ++k) {
            auto [sum, idx] = pq.top();
            pq.pop();

            if (k >= left) {
                res = (res + sum) % MOD;
            }

            if (idx + 1 < n) {
                pq.push({sum + nums[idx + 1], idx + 1});
            }
        }

        return res;
    }
};
