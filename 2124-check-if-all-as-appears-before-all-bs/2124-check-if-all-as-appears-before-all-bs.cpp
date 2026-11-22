class Solution {
public:
    bool checkString(string s) {
        int a=-1,b=-1;
        int n=s.size();
        for(int i=0; i+1<n; i++){
            if(s[i]=='b' && s[i+1]=='a') return false;
        }
        return true;
    }
};
// class Solution {
// public:
//     bool checkString(string s) {
//         int a=-1,b=-1;
//         int n=s.size();
//         for(int i=0; i<n; i++){
//             if(s[i]=='a') a = i;
//         }
//         for(int i=0; i<n; i++){
//             if(s[i]=='b'){
//                 b=i;
//                 break;
//             }
//         }
//         if(b==-1) return true;

//         return b>a;
//     }
// };