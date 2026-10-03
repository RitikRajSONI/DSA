class Solution {
public:
    int longestValidParentheses(string s) {
        int o=0,c=0,ans=0;
        int sz=s.size();
        for(int i=0; i<sz; i++){
            if(s[i]=='(') o++;
            else c++;

            if(o<c){
                o=c=0;
            }else if(o==c){
                ans=max(ans,o+c);
            }
        }
        c=0;
        o=0;
        for(int i=sz-1; i>=0; i--){
            if(s[i]==')') c++;
            else o++;

            if(o>c){
                o=c=0;
            }else if(o==c){
                ans=max(ans,o+c);
            }
        }
        return ans;
    }
};