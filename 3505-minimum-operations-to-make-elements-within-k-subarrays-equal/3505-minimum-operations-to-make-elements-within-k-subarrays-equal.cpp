class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        int m = n - x + 1;                 // number of windows
        vector<long long> cost(m);

        // ---- fast cost of every window (sliding median) ----
        multiset<int> lo, hi;              // lo = lower half (size ceil(x/2)), hi = upper half
        long long sLo = 0, sHi = 0;        // sums of each half

        for (int i = 0; i < n; i++) {
            // add nums[i]
            if (lo.empty() || nums[i] <= *lo.rbegin()) { lo.insert(nums[i]); sLo += nums[i]; }
            else { hi.insert(nums[i]); sHi += nums[i]; }

            // remove nums[i-x] once the window is too big
            if (i >= x) {
                int v = nums[i - x];
                auto it = lo.find(v);
                if (it != lo.end()) { lo.erase(it); sLo -= v; }
                else { hi.erase(hi.find(v)); sHi -= v; }
            }

            // rebalance so that lo.size() == hi.size() or hi.size()+1
            while (lo.size() > hi.size() + 1) {
                auto it = prev(lo.end());
                int v = *it;
                lo.erase(it); sLo -= v;
                hi.insert(v); sHi += v;
            }
            while (lo.size() < hi.size()) {
                auto it = hi.begin();
                int v = *it;
                hi.erase(it); sHi -= v;
                lo.insert(v); sLo += v;
            }

            if (i >= x - 1) {
                long long med = *lo.rbegin();
                cost[i - x + 1] = med * (long long)lo.size() - sLo
                                + sHi - med * (long long)hi.size();
            }
        }

        // ---- DP (unchanged) ----
        const long long INF = LLONG_MAX / 4;
        vector<vector<long long>> dp(k + 1, vector<long long>(m + x + 1, INF));
        for (int s = 0; s < (int)dp[0].size(); s++) dp[0][s] = 0;

        for (int r = 1; r <= k; r++) {
            for (int s = m - 1; s >= 0; s--) {
                long long skip = dp[r][s + 1];
                long long take = cost[s] + dp[r - 1][s + x];
                dp[r][s] = min(skip, take);
            }
        }
        return dp[k][0];
    }
};

// class Solution {
// public:
//     long long minOperations(vector<int>& nums, int x, int k) {
//         int n = nums.size();
//         int m = n - x + 1;                 // number of windows
//         vector<long long> cost(m);

//         // ---- your part: cost of every window ----
//         int i = 0, j = x - 1;
//         for (; j < n; j++, i++) {
//             vector<int> arr;
//             for (int h = i; h <= j; h++) arr.push_back(nums[h]);
//             sort(arr.begin(), arr.end());
//             int med = arr[x / 2];
//             long long Wsum = 0;
//             for (int h = 0; h < x; h++) Wsum += abs(med - arr[h]);
//             cost[i] = Wsum;
//         }

//         // ---- replaces the priority_queue ----
//         // dp[r][s] = min cost to pick r windows using start positions >= s
//         const long long INF = LLONG_MAX / 4;
//         vector<vector<long long>> dp(k + 1, vector<long long>(m + x + 1, INF));
//         for (int s = 0; s < (int)dp[0].size(); s++) dp[0][s] = 0;

//         for (int r = 1; r <= k; r++) {
//             for (int s = m - 1; s >= 0; s--) {
//                 long long skip = dp[r][s + 1];                    // don't start a window at s
//                 long long take = cost[s] + dp[r - 1][s + x];      // start one at s, next must begin at s+x or later
//                 dp[r][s] = min(skip, take);
//             }
//         }
//         return dp[k][0];
//     }
// };


// class Solution {
// public:
//     typedef pair<long long,int> P; 
//     long long minOperations(vector<int>& nums, int x, int k) {
//         int i=0,j=x-1;
//         int n=nums.size();
//         priority_queue<P, vector<P>, greater<P>> pq;
//         for(; j<n; j++,i++){
//             vector<int> arr;
//             for(int h=i; h<=j; h++){
//                 arr.push_back(nums[h]);
//             }
//             sort(arr.begin(),arr.end());
//             int med = arr[x/2];
//             long long Wsum=0;
//             for(int h=0; h<x; h++){
//                 Wsum+=abs(med-arr[h]);
//             }
//             pq.push({Wsum,i});
//         }

//         long long ans=0;
//         auto p=pq.top(); pq.pop();
//         k--;
//         ans+=p.first;
//         while(k>0 && !pq.empty()){
//             auto f=pq.top(); pq.pop();
//             if(abs(p.second-f.second)<x) continue;
//             p=f;
//             ans+=f.first;
//             k--;
//         }
//         return ans;
//     }
// };