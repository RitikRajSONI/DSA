class Solution {
public:
    typedef vector<double> V;
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n=arr.size();
        priority_queue<V,vector<V>, greater<V>> pq;
        for(int i=0; i<n; i++){
            pq.push({1.0*arr[i]/arr[n-1], 1.0*i, 1.0*(n-1)});
        }
        int s=1;
        while(s<k){
            V vec=pq.top();
            pq.pop();

            int i=vec[1];
            int j=vec[2]-1;

            pq.push({1.0*arr[i]/arr[j], 1.0*i, 1.0*j});
            s++;
        }
        
        V res=pq.top();
        int i=res[1];
        int j=res[2];
        return {arr[i],arr[j]};
    }
};


// class Solution {
// public:

//     vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
//         int n=arr.size();
//         priority_queue<vector<double>> pq;
//         for(int i=0; i<n-1; i++){
//             for(int j=i+1; j<n; j++){
//                 double div=1.0*arr[i]/arr[j];
//                 pq.push({div,1.0*arr[i],1.0*arr[j]});
//                 if(pq.size()>k){
//                     pq.pop();
//                 }
//             }
//         }
//         auto res=pq.top();
//         return {(int)res[1],(int)res[2]};
//     }
// };