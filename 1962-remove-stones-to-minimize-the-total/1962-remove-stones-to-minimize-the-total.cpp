class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        // priority_queue<int> pq;
        // for(int i=0; i<piles.size(); i++){
        //     pq.push(piles[i]);
        // }
        priority_queue<int> pq(piles.begin(), piles.end());
        while(k>0){
            int a=pq.top(); pq.pop();
            pq.push((a+1)/2);
            k--;
        }
        int ans=0;
        while(!pq.empty()){
            ans+=pq.top(); pq.pop();
        }

        return ans;
    }   
};