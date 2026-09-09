class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        for(long long i = 1000;i<=n;i*=1000){
            ans += n - i + 1;
        }
        return ans;
    }
};

// class Solution {
// public:
//     typedef long long L;
//     L countCommas(L n) {
//         if(n<1000) return 0;
//         L totalCommmas=0;
//         L threshHold=1000;
//         while(n>=threshHold){
//             totalCommmas+=(n-threshHold+1);
//             if(threshHold > LLONG_MAX/1000){
//                 break;
//             }
//             threshHold*=1000;
//         }

//         return totalCommmas;
//     }
// };