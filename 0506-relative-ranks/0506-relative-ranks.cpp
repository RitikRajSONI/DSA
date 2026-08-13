class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        vector<int> d=score;
        sort(d.begin(),d.end());
        unordered_map<int,int> mp;
        for(int i=n-1; i>=0; i--){
            mp[d[i]] = n-i;
        }
        vector<string> ans;
        for(int i=0; i<n; i++){
            if(mp[score[i]] == 1){
                ans.push_back("Gold Medal");
            }
            else if(mp[score[i]] == 2){
                ans.push_back("Silver Medal");
            }
            else if(mp[score[i]] == 3){
                ans.push_back("Bronze Medal");
            }else{
                ans.push_back(to_string(mp[score[i]]));
            }
        }
        return ans;
    }
};