// Bottom Up :
class Solution {
public:
    int countSubstrings(string s) {
        int n= s.size();
        vector<vector<bool>> dp(n+1,vector<bool> (n+1,false));
        int cnt = 0;
        for(int L=1; L<=n; L++){
            for(int i=0; i+L-1<n; i++){
                int j = i+L-1;
                if(i==j){ 
                    dp[i][j] = true;
                }
                else if(i+1==j){
                    dp[i][j]=(s[i]==s[j]);
                }else{
                    dp[i][j] = (s[i]==s[j] && dp[i+1][j-1]);
                }


                if(dp[i][j]==true) cnt++;
            }
        }
        return cnt;
    }
};

// Brute Force Approach :
// class Solution {
// public:
//     bool ispalindrome(string s){
//         if(s.size()==1) return true;
//         string rev=s;
//         reverse(rev.begin(),rev.end());
//         return rev==s;
//     }
//     int countSubstrings(string s) {
//         int ans=0,n=s.size();
//         for(int i=0; i<n; i++){
//             string x="";
//             for(int j=i; j<n; j++){
//                 x+=s[j];
//                 if(ispalindrome(x)) ans++;
//             }
//         }
//         return ans;
//     }
// };