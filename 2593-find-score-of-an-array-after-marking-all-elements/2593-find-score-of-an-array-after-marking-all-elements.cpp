class Solution {
public:
    typedef pair<int,int> P;
    long long findScore(vector<int>& nums) {
        int n=nums.size();
        priority_queue<P,vector<P>,greater<P>> pq;
        for(int i=0; i<n; i++){
            pq.push({nums[i], i});
        }
        vector<bool> marked(n,false);

        long long ans=0;
        while(!pq.empty()){
            int val = pq.top().first;
            int idx= pq.top().second;  pq.pop();
            if(!marked[idx]){
                ans+=val;
                marked[idx]=true;;
                if(idx>0) marked[idx-1]=true;
                if(idx<n-1) marked[idx+1]=true;
            }
            else continue;
        }
        return ans;
    }
};
