class Solution {
public:
    unordered_map<string, int> dp;
    bool check_unq(string s1, string s2){
        unordered_set<char> mp;
        for(char c:s1){
            if(mp.find(c) != mp.end()) return false;  
            mp.insert(c);
        }
        for(char c:s2){
            if(mp.find(c) != mp.end()) return false;  
            mp.insert(c);
        }
        return true;
    }
    int solve(vector<string>& arr, int i, string p){
        if(i>=arr.size()) return 0;

        string key = to_string(i) + "_" + p;
        if (dp.count(key)) {
            return dp[key];
        }

        int take = 0;
        //take:
        if (check_unq(arr[i], p)) { 
            take = arr[i].size() + solve(arr, i + 1, arr[i] + p);
        }

        //skip:
        int skip = solve(arr,i+1,p);

        return dp[key] = max(take,skip);
    }
    int maxLength(vector<string>& arr) {
        return solve(arr,0,"");
    }
};