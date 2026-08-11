class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l=0,r=arr.size()-1;
        while(l<r){
            int m=l+(r-l)/2;
            if(arr[m] < arr[m+1]) l=m+1;
            else r=m;
        }
        return l;
    }
};

// class Solution {
// public:
//     int peakIndexInMountainArray(vector<int>& arr) {
//         int l=0,r=arr.size()-1;
//         int m;
//         while(l<=r){
//             m=l+(r-l)/2;
//             if(m>0 && m<arr.size()-1 && arr[m]>arr[m-1] && arr[m]>arr[m+1]){
//                 return m;
//             }
//             else if(m>0 && arr[m]<arr[m-1]){
//                 r=m-1;
//             }else{
//                 l=m+1;
//             }
//         }
//         return m;
//     }
// };