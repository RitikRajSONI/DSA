class Solution {
public:
    int M = 1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        int cs=0;
        int ans=0,ce=1,co=0;
        for(int i=0; i<n; i++){
            cs+=arr[i];
            if(cs%2!=0){
                ans = (ans+ce)%M;
                co++;
            }else{
                ans = (ans+co)%M;
                ce++;
            }
        }
        return ans;
    }
};
// class Solution {
// public:
//     int M = 1e9+7;
//     int numOfSubarrays(vector<int>& arr) {
//         int n=arr.size();
//         if(n==1) return arr[0]%2!=1;
//         vector<int> prf(n);
//         int cs=0;
//         for(int i=0; i<n; i++){
//             cs+=arr[i];
//             prf[i]=cs;
//         }
//         int ans=0,ce=1,co=0;
//         for(int i=0; i<n; i++){
//             if(prf[i]%2!=0){
//                 ans = (ans+ce)%M;
//                 co++;
//             }else{
//                 ans = (ans+co)%M;
//                 ce++;
//             }
//         }
//         return ans;
//     }
// };
// class Solution {
// public:
//     int numOfSubarrays(vector<int>& arr) {
//         int n=arr.size();
//         if(n==1) return arr[0]%2!=1;
//         int cs=0;
//         int l=0,r=0;
//         int ans=0;
//         for(int i=0; i<n; i++){
//             int cs=0;
//             for(int j=i; j<n; j++){
//                 cs+=arr[j];
//                 if(cs%2!=0) ans++;
//             }
//         }
//         return ans;
//     }
// };