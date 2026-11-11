class Solution {
public:
    typedef long long ll;
    long long minimumCost(int c1, int c2, int cb, int n1, int n2) {
        if(1LL*c1+c2  <= cb ) return 1LL*n1*c1+1LL*n2*c2;
        ll ans=0;
        ll common = min(n1,n2);
        ans+=common*cb;
        if(n1>n2){ 
            ans+=1LL*(n1-n2)*min(c1,cb);
        }
        else { 
            ans+=1LL*(n2-n1)*min(c2,cb);
        }

        return ans;
    }
};