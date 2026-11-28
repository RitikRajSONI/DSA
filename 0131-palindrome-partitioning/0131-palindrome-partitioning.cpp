class Solution {
public:
    void backtrack(int start, const string& s, vector<vector<bool>>& dp, 
                   vector<string>& current, vector<vector<string>>& res) {
        // Base case: reached the end of the string
        if (start == s.size()) {
            res.push_back(current);
            return;
        }

        // Try every possible end index for the next palindromic substring
        for (int end = start; end < s.size(); end++) {
            if (dp[start][end]) {
                current.push_back(s.substr(start, end - start + 1)); // Choose
                backtrack(end + 1, s, dp, current, res);             // Explore
                current.pop_back();                                  // Unchoose
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        // 1. Precompute all palindromic substrings
        for (int i = 0; i < n; i++) dp[i][i] = true;

        for (int L = 2; L <= n; L++) {
            for (int i = 0; i + L - 1 < n; i++) {
                int j = i + L - 1;
                if (s[i] == s[j]) {
                    dp[i][j] = (L == 2) ? true : dp[i + 1][j - 1];
                }
            }
        }

        // 2. Use backtracking to build complete partitions
        vector<vector<string>> res;
        vector<string> current;
        backtrack(0, s, dp, current, res);
        
        return res;
    }
};

// class Solution {
// public:
//     int n;
//     vector<vector<string>> res;
//     bool isPalindrome(string& s, int i, int j){
//         while(i<=j){
//             if(s[i]!=s[j]) return false;
//             i++;
//             j--;
//         }
//         return true;
//     }

//     void backtrack(string& s, int idx, vector<string> cur){
//         if(idx==n){
//             res.push_back(cur);
//             return;
//         }

//         for(int i=idx; i<n; i++){
//             if(isPalindrome(s,idx,i)){
//                 cur.push_back(s.substr(idx,i-idx+1));
//                 backtrack(s,i+1,cur);
//                 cur.pop_back();
//             }
//         }
//     }
//     vector<vector<string>> partition(string s) {
//         n= s.size();
//         vector<string> cur;
//         backtrack(s,0,cur);
//         return res;
//     }
// };