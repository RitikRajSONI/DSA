class Solution {
public:
    typedef pair<int,char> P;
    string longestDiverseString(int a, int b, int c) {
        priority_queue<P> pq;
        if(a>0) pq.push({a,'a'}); 
        if(b>0) pq.push({b,'b'}); 
        if(c>0) pq.push({c,'c'});

        string res="";
        while(!pq.empty()){
            int cur_count=pq.top().first;
            char cur_char=pq.top().second;
            pq.pop();
            int rs=res.length();
            if(rs>1 && cur_char==res[rs-1] && cur_char==res[rs-2]){
                if(pq.empty()) break;
                int nxt_count = pq.top().first;
                int nxt_char = pq.top().second;
                pq.pop();

                res.push_back(nxt_char);
                nxt_count--;
                if(nxt_count>0) pq.push({nxt_count,nxt_char});
            }else{
                cur_count--;
                res.push_back(cur_char);
            }

            if(cur_count>0) pq.push({cur_count,cur_char});
        } 
        return res;
    }
};