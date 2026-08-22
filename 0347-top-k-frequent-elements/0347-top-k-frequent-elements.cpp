class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int, int> mp;
        
        for(int &num : nums) {
            mp[num]++;
        }
        
        //index = frequency
        //Value will be elements
        //bucket[i] = elements occuring ith time
        vector<vector<int>> bucket(n+1);
        
        for(auto &it : mp) {
            int element = it.first;
            int freq    = it.second;
            
            bucket[freq].push_back(element);
        }
        
        //Pick from right to left to find max frequency elements
        vector<int> result;
        for(int i = n; i >= 0; i--) {
            
            if(bucket[i].size() == 0) continue;
            
            int size = bucket.size();
            while(bucket[i].size() > 0 && k > 0) {
                result.push_back(bucket[i].back());
                bucket[i].pop_back();
                k--;
            }
            
        }
        
        return result;
    }
};


/*

Time Complexity : O(N log K)
Space Complexity : O(N + K)

Code:
class Solution {
public:
    typedef pair<int, int> P;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> fr;
        for (const int &e : nums) {
            fr[e]++;
        } 
        
        // Min-heap to keep the top k frequent elements
        priority_queue<P, vector<P>, greater<P>> pq;
        for (const auto &[e, f] : fr) {
            pq.push({f, e});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        // Extract elements from the heap
        vector<int> res;
        res.reserve(k); 
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        return res;
    }
};

*/