class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<int> indeg(numCourses,0);
        vector<vector<int>> adj(numCourses);
        for(auto &pre:prerequisites){
            int a=pre[0];
            int b=pre[1];
            // b ---> a
            indeg[a]++;
            adj[b].push_back(a);
        }

        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(indeg[i]==0) q.push(i);
        }

        int cnt=0;
        while(!q.empty()){
            int u = q.front(); q.pop();
            cnt++;
            for(int &v:adj[u]){
                indeg[v]--;
                if(indeg[v]==0) q.push(v);
            }
        }

        return cnt==numCourses;
    }
};





// class Solution {
// public:
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         int n = prerequisites.size();
//         vector<int> indeg(numCourses,0);
//         unordered_map<int,vector<int>> adj;
//         for(int i=0; i<n; i++){
//             indeg[prerequisites[i][0]]++;
//             adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
//         }

//         queue<int> q;
//         for(int i=0; i<numCourses; i++){
//             if(indeg[i]==0) q.push(i);
//         }

//         int cnt=0;
//         while(!q.empty()){
//             int u = q.front(); q.pop();
//             cnt++;
//             for(int &v:adj[u]){
//                 indeg[v]--;
//                 if(indeg[v]==0) q.push(v);
//             }
//         }

//         return cnt==numCourses;
//     }
// };