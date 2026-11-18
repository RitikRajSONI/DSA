class Solution {
public:
    int N,M,K;
    int MOD = 1e9+7;
    int dp[51][51][101];
    int solve(int idx, int SC, int MSF){
        if(idx==N){
            return SC==K? 1:0;
        }
        if(dp[idx][SC][MSF]!=-1) return dp[idx][SC][MSF];
        int res=0;
        for(int i=1; i<=M; i++){
            if(i>MSF){
                res = (res+solve(idx+1,SC+1,i))%MOD;
            }else{
                res = (res+solve(idx+1,SC,MSF))%MOD;
            }
        }

        return dp[idx][SC][MSF] = res%MOD;
    }
    int numOfArrays(int n, int m, int k) {
        N=n;
        M=m;
        K=k;
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0);
    }
};