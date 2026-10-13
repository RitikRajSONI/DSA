class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int,vector<int>> adj;
        unordered_map<int,int> indeg,outdeg;
        for(auto pr:pairs){
            int u=pr[0];
            int v=pr[1];
            adj[u].push_back(v);
            indeg[v]++;
            outdeg[u]++;
        }
        int start=pairs[0][0];
        for(auto &it:adj){
            int node=it.first;
            if(outdeg[node]-indeg[node]==1){ 
                start=node;
                break;
            }
        }
        vector<int> ep;
        stack<int> st;
        st.push(start);
        while(!st.empty()){
            int cur=st.top();
            if(!adj[cur].empty()){
                int nbr=adj[cur].back();
                adj[cur].pop_back();
                st.push(nbr);
            }else{
                ep.push_back(cur);
                st.pop();
            }
        }
        reverse(ep.begin(), ep.end());
        vector<vector<int>> ans;
        for(int i=0; i+1<ep.size(); i++){
            ans.push_back({ep[i],ep[i+1]});
        }

        return ans;
    }
};