class Solution {
public:
    typedef long long L;
    L countCommas(L n) {
        if(n<1000) return 0;
        L totalCommmas=0;
        L threshHold=1000;
        while(n>=threshHold){
            totalCommmas+=(n-threshHold+1);
            if(threshHold > LLONG_MAX/1000){
                break;
            }
            threshHold*=1000;
        }

        return totalCommmas;
    }
};