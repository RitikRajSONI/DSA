class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        unordered_map<char, int> mp;
        string ans = "";
        int l = 0, n = s.size();
        
        for (int r = 0; r < n; r++) {
            mp[s[r]]++;
            while (mp['1'] > k || s[l] == '0') {
                if (s[l] == '1') mp['1']--;
                l++;
            }
            if (mp['1'] == k) {
                string t = s.substr(l, r - l + 1);
                if (ans == "" || t.size() < ans.size()) {
                    ans = t;
                } else if (t.size() == ans.size() && t < ans) {
                    ans = t;
                }
            }
        }
        return ans;
    }
};

// class Solution {
// public:
//     string shortestBeautifulSubstring(string s, int k) {
//         unordered_map<char,int> mp;
//         string ans="";
//         int l=0,n=s.size();
//         for(int r=0; r<n; r++){
//             mp[s[r]]++;
//             while(mp['1']>k || s[l]=='0'){
//                 if(s[l]=='1') mp['1']--;
//                 l++;
//             }
//             // if(mp['1']==k && r-l+1<ans.size()){
//             //     ans=s.substr(l,r-l+1);
//             // }
//             if (mp['1'] == k) {
//                 string t = s.substr(l, r - l + 1);
//                 if (t.size() < ans.size()) {
//                     ans = t;
//                 } else if (t.size() == ans.size() && t < ans) {
//                     ans = t;
//                 }
//             }
//         }
//         return ans.size()==n? "":ans;
//     }
// };