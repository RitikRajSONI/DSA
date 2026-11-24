// Bottom Up :
class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));

        for(int i=0; i<=m; i++){
            for(int j=0; j<=n; j++){
                if(i==0 || j==0){
                    dp[i][j]=i+j;
                }
                else if(s1[i-1]==s2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }else{
                    dp[i][j] = 1 + min(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        string res="";
        int i=m,j=n;
        while(i>0 && j>0){
            if(s1[i-1]==s2[j-1]){
                res.push_back(s1[i-1]);
                i--;
                j--;
            }else{
                if(dp[i-1][j] < dp[i][j-1]){
                    res.push_back(s1[i-1]);
                    i--;
                }else{
                    res.push_back(s2[j-1]);
                    j--;
                }
            }
        }

        while(i>0) res.push_back(s1[--i]);
        while(j>0) res.push_back(s2[--j]);

        reverse(res.begin(),res.end());

        return res;
    }
};


// class Solution {
// public:
//     string shortestCommonSupersequence(string s1, string s2) {
//         int m = s1.size();
//         int n = s2.size();
//         vector<vector<string>> dp(m+1,vector<string>(n+1,""));
//         for (int i = 1; i <= m; i++) dp[i][0] = s1.substr(0, i);
//         for (int j = 1; j <= n; j++) dp[0][j] = s2.substr(0, j);

//         for(int i=1; i<=m; i++){
//             for(int j=1; j<=n; j++){
//                 if(s1[i-1]==s2[j-1]){
//                     dp[i][j] = dp[i-1][j-1] + s1[i-1];
//                 }else{
//                     if (dp[i][j - 1].size() < dp[i - 1][j].size()) {
//                         dp[i][j] = dp[i][j - 1] + s2[j - 1]; // Changed s1[i-1] -> s2[j-1]
//                     } else {
//                         dp[i][j] = dp[i - 1][j] + s1[i - 1]; // Changed s2[j-1] -> s1[i-1]
//                     }
//                 }
//             }
//         }

//         return dp[m][n];
//     }
// };


// Recursion + Memoisation :
// class Solution {
// public:
//     unordered_map<string,string> mp;
//     string solve(const string& s1, const string& s2, int i, int j){
//         if(i>=s1.size()){
//             return s2.substr(j);
//         }
//         if(j>=s2.size()){
//             return s1.substr(i);
//         }

//         string k = to_string(i)+ "_" +to_string(j);
//         if(mp.contains(k)) return mp[k];

//         if(s1[i]==s2[j]){
//             return mp[k] = s1[i]+solve(s1,s2,i+1,j+1);
//         }
//         string sk1 = s1[i]+solve(s1,s2,i+1,j); 
//         string sk2 = s2[j]+solve(s1,s2,i,j+1);

//         return mp[k] = sk1.size()<=sk2.size()? sk1:sk2;
//     }
//     string shortestCommonSupersequence(string s1, string s2) {
//         return solve(s1,s2,0,0);
//     }
// };