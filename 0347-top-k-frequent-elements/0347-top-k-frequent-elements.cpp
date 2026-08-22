class Solution {
public:
    typedef pair<int,int> P;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<P,vector<P>> pq;
        unordered_map<int,int> fr;
        for(int &e:nums){
            fr[e]++;
        } 
        for(auto const &[e,f]:fr){
            pq.push({f,e});
        }
        vector<int> res;
        for(int i=1; i<=k; i++){
            P te=pq.top(); pq.pop();
            res.push_back(te.second);
        }
        return res;
    }
};