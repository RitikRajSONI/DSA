class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        queue<int> q;
        vector<bool> visited(n,false);
        q.push(0);
        visited[0]=true;
        while(!q.empty()){
            int u=q.front(); q.pop();
            for(auto v:rooms[u]){
                if(!visited[v]){
                    visited[v]=true;
                    q.push(v);
                }
            }
        }
        for(bool v:visited){
            if(v==false) return false;
        }
        return true;
    }
};