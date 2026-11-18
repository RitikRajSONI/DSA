class Solution {
public:
    int minChanges(string s) {
        int n= s.size();
        if(n==2) return s[0]==s[1]? 0:1;
        int ans=0;
        for(int i=0; i<n; i+=2){
            if(s[i]!=s[i+1]) ans++;
        }
        return ans;
    }
};