#include <string>
#include <vector>
#include <unordered_map>

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        // 1. Optimize Map Insertion: Use const references to prevent copying elements
        unordered_map<string, string> mp;
        for (const auto& svc : knowledge) {
            mp[svc[0]] = svc[1];
        }
        
        string res = "";
        // 2. Prevent Reallocations: Pre-allocate string buffer space to boost speed
        res.reserve(s.size()); 
        
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                // Track indices to construct the key substring without character-by-character appending
                int start = ++i; 
                while (i < n && s[i] != ')') {
                    i++;
                }
                
                // Extract key directly using substr
                string temp = s.substr(start, i - start);
                
                // Fast hash map lookup
                auto it = mp.find(temp);
                if (it != mp.end()) {
                    res += it->second;
                } else {
                    res += '?';
                }
            } else {
                res += s[i];
            }
        }
        return res;
    }
};

// class Solution {
// public:
//     string findString(string temp, vector<vector<string>>& knowledge){
//         string str="";
//         for(auto strvec:knowledge){
//             if(strvec[0]==temp){
//                 str=strvec[1];
//                 break;
//             }
//         }
//         return str==""? "?":str;
//     }
//     string evaluate(string s, vector<vector<string>>& knowledge) {
//         int n = s.size();
//         string res="";
//         for(int i=0; i<n; i++){
//             if(s[i]=='('){
//                 string temp="";
//                 while(s[++i]!=')' && i<n){
//                     temp+=s[i];
//                 }
//                 string val = findString(temp,knowledge);
//                 res+=val;
//             }else{
//                 res+=s[i];
//             }
//         }
//         return res;
//     }
// };