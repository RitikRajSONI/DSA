class Solution {
public:
    typedef pair<char,int> P;
    struct comp{
        bool operator()(P &p1, P &p2){
            if(p1.first==p2.first){
                return p1.second<p2.second;
            }
            return p1.first>p2.first;
        }
    };
    string clearStars(string s) {
        int n=s.size();
        priority_queue<P, vector<P> , comp> pq;
        for(int i=0; i<n; i++){
            if(s[i]!='*'){
                pq.push({s[i], i});
            }else{
                int idx=pq.top().second;
                pq.pop();
                s[idx]='*';
            }
        }
        string ans="";
        for(int i=0; i<n; i++){
            if(s[i]=='*') continue;
            ans+=s[i];
        }
        return ans;
    }
};


// class Solution {
// public:
//     typedef pair<int,int> P;
//     string clearStars(string s) {
//         int n=s.size();
//         priority_queue<P, vector<P> , greater<P>> pq;
//         for(int i=0; i<n; i++){
//             pq.push({s[i]-'*', i});
//             if(pq.size()>1 && s[i]=='*'){
//                 pq.pop(); pq.pop();
//             }
//         }
//         priority_queue<int, vector<int> , greater<int>> pqd;
//         while(!pq.empty()){
//             int idx=pq.top().second;
//             pqd.push(idx);
//             pq.pop();
//         }
//         string ans="";
//         while(!pqd.empty()){
//             ans+=s[pqd.top()];
//             pqd.pop();
//         }
//         return ans;
//     }
// };