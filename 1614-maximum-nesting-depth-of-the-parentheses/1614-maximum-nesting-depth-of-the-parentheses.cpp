class Solution {
public:
    int maxDepth(string s) {
        int p=0,mxdp=0;
        for(auto c:s){
            if(c=='(') p++;
            if(c==')') p--;
            mxdp=max(mxdp,p);
        }
        return mxdp;
    }
};