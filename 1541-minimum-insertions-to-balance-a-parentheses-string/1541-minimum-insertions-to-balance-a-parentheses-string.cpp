class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;   // Tracks required insertions
        int right = 0; // Tracks the number of ')' needed
        
        for (char c : s) {
            if (c == '(') {
                right += 2;
                // If we had an odd number of needed ')', we must fix it immediately
                // because a new '(' cannot pair with a single leftover ')' from before.
                if (right % 2 != 0) {
                    ans++;   // Insert a ')' to complete the pair
                    right--; // One less ')' needed now
                }
            } else { // c == ')'
                right--;
                // If we need a negative amount of ')', it means we got an extra ')'
                if (right < 0) {
                    ans++;     // Insert a missing '('
                    right += 2; // That new '(' now requires two ')' (one is met by current ')' )
                }
            }
        }
        
        return ans + right;
    }
};


// class Solution {
// public:
//     int minInsertions(string s) {
//         int n=s.size();
//         stack<char> st;
//         int cnt=0;
//         for(int i=0; i<n; i++){
//             if(s[i]=='('){
//                 st.push('(');
//             }else{
//                 if(!st.empty()){
//                     if(i+1<n && s[i]==')' && s[i+1]==')'){
//                         i++;
//                     }
//                     else cnt++;
//                     st.pop();
//                 }
//                 else cnt+=2;
//             }
            
//         }
//         return cnt;
//     }
// };