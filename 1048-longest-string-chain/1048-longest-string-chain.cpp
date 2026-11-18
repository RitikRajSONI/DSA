class Solution {
public:
    bool checkPdssr(string& s1, string& s2){
        int m=s1.size();
        int n=s2.size();
        if(n-m!=1) return false;
        int i=0,j=0;
        while(i<m && j<n){
            if(s1[i]==s2[j]) i++;
            j++;
        }
        return i==m;
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });
        int ans=1;
        vector<int> dp(n,1);
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(words[i].size() - words[j].size() > 1) continue;
                if(checkPdssr(words[j],words[i])){
                    dp[i]=max(dp[j]+1,dp[i]);
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};
// class Solution {
// public:
//     bool checkPdssr(string& s1, string& s2){
//         int m=s1.size();
//         int n=s2.size();
//         if(n-m!=1) return false;
//         int i=0,j=0;
//         while(i<m && j<n){
//             if(s1[i]==s2[j]) i++;
//             j++;
//         }
//         return i==m;
//     }
//     vector<vector<int>> dp;
//     int solve(vector<string>& words, int i, int p){
//         if(i>=words.size()) return 0;
//         if(dp[i][p+1]!=-1) return dp[i][p+1];
//         int take=0,skip=0;
//         // take
//         if(p==-1 || checkPdssr(words[p],words[i])){
//             take = 1+solve(words,i+1,i);
//         } 
//         // skip
//         skip=solve(words,i+1,p);

//         return dp[i][p+1]=max(take,skip);
//     }
//     int longestStrChain(vector<string>& words) {
//         int n = words.size();
//         sort(words.begin(), words.end(), [](const string& a, const string& b) {
//             return a.size() < b.size();
//         });
//         dp.resize(n+1,vector<int>(n+1,-1));
//         return solve(words,0,-1);
//     }
// };