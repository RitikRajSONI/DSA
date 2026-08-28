class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k=nums.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int mxe=INT_MIN;
        for(int i=0; i<k; i++){
            pq.push({nums[i][0], i, 0});
            mxe=max(mxe,nums[i][0]);
        }
        vector<int> range={-100000,100000};  //(a,b)
        while(!pq.empty()){
            vector<int> curmin = pq.top(); pq.pop();
            int mne=curmin[0];
            int listidx=curmin[1];
            int idx=curmin[2];

            if(mxe-mne < range[1]-range[0]){
                range[0]=mne;
                range[1]=mxe;
            }

            if(idx+1 < nums[listidx].size()){
                int nxtel=nums[listidx][idx+1];
                pq.push({nxtel, listidx, idx+1});
                mxe=max(mxe,nxtel);
            }else break;
        }

        return range;
    }
};
// class Solution {
// public:
//     vector<int> smallestRange(vector<vector<int>>& nums) {
//         int k=nums.size();
//         vector<int> vec(k,0);
//         vector<int> range={-100000,100000};  //(a,b)
//         while(true){
//             int mne=INT_MAX;
//             int mxe=INT_MIN;
//             int mnei=0;
//             for(int i=0; i<k; i++){
//                 int listidx=i;
//                 int elidx=vec[i];
//                 int el=nums[listidx][elidx];

//                 if(el<mne){
//                     mne=el;
//                     mnei=listidx;
//                 } 
                
//                 mxe=max(mxe,el);
//             }

//             if(mxe-mne < range[1]-range[0]){
//                 range[0]=mne;
//                 range[1]=mxe;
//             }

//             int nextIdx=vec[mnei]+1;
//             if(nextIdx >= nums[mnei].size()) break;
//             vec[mnei]=nextIdx;
//         }
//         return range;
//     }
// };