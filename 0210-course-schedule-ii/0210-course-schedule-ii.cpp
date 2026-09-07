class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<int> indeg(numCourses,0);
        vector<vector<int>> adj(numCourses);
        for(auto &pre:prerequisites){
            int a=pre[0];
            int b=pre[1];
            // b--->a
            indeg[a]++;
            adj[b].push_back(a);
        }

        vector<int> order;
        order.reserve(numCourses);
        for(int i=0; i<numCourses; i++){
            if(indeg[i]==0) order.push_back(i);
        }
        int head=0;
        while(head<order.size()){
            int u = order[head++];
            for(int &v:adj[u]){
                indeg[v]--;
                if(indeg[v]==0) order.push_back(v);
            }
        }

        if(order.size()!=numCourses) return {};
        return order;
    }
};




// class Solution {
// public:
//     vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
//         int n = prerequisites.size();
//         vector<int> indeg(numCourses,0);
//         vector<vector<int>> adj(numCourses);
//         for(auto &pre:prerequisites){
//             int a=pre[0];
//             int b=pre[1];
//             // b--->a
//             indeg[a]++;
//             adj[b].push_back(a);
//         }

//         queue<int> q;
//         for(int i=0; i<numCourses; i++){
//             if(indeg[i]==0) q.push(i);
//         }
        
//         vector<int> ts;
//         while(!q.empty()){
//             int u = q.front(); q.pop();
//             ts.push_back(u);
//             for(int &v:adj[u]){
//                 indeg[v]--;
//                 if(indeg[v]==0) q.push(v);
//             }
//         }

//         if(ts.size()!=numCourses) return {};
//         return ts;
//     }
// };