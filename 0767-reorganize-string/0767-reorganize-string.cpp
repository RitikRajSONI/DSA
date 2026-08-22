class Solution {
public:
    string reorganizeString(string s) {
        int n=s.size();
        if(n==1) return s;
        vector<int> count(26,0);
        char mostFrequent;
        int maxFrequency=0;
        for(auto &c:s){
            count[c-'a']++;
            if(count[c-'a'] > maxFrequency){
                mostFrequent=c;
                maxFrequency=count[c-'a'];
            }
            if(count[c-'a'] > (n+1)/2) return "";
        }
        string res=s;
        int i=0;
        while(count[mostFrequent-'a']>0){
            res[i]=mostFrequent;
            i+=2;
            count[mostFrequent-'a']--;
        } 
        for(char ch='a'; ch<='z'; ch++){
            while(count[ch-'a']>0){
                if(i>=n) i=1;
                res[i]=ch;
                i+=2;
                count[ch-'a']--;
            }         
        }

        return res;
    }
};

/*
class Solution {
public:
    typedef pair<int,char> P;
    string reorganizeString(string s) {
        int n=s.size();
        if(n==1) return s;
        vector<int> count(26,0);
        for(auto &c:s){
            count[c-'a']++;
            if(count[c-'a'] > (n+1)/2) return "";
        }

        priority_queue< P ,vector<P>> pq;

        for(char ch='a'; ch<='z'; ch++){
            if(count[ch-'a'] > 0) pq.push({count[ch-'a'], ch});
        }

        string res="";
        while(pq.size()>=2){
            auto P1 = pq.top(); pq.pop();
            auto P2 = pq.top(); pq.pop();

            res.push_back(P1.second); P1.first--;
            res.push_back(P2.second); P2.first--;

            if(P1.first > 0) pq.push(P1);
            if(P2.first > 0) pq.push(P2);
        }

        if(!pq.empty()){
            res.push_back(pq.top().second);
        }
        return res;
    }
};
*/