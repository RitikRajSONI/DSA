class Solution {
public:
    //store count of subtrees of each node
    long result_base_node = 0;
    vector<int> count;
    int N;
    int dfsBase(unordered_map<int, vector<int>> &adj, int curr_node, int prev_node, int curr_depth) {
        int total_node = 1;
        
        result_base_node += curr_depth;
        
        for(int &child : adj[curr_node]) {
            if(child == prev_node)
                continue;
            
            total_node += dfsBase(adj, child, curr_node, curr_depth+1);
        }
        
        //store count of subtrees of each node
        count[curr_node] = total_node;
        
        return total_node;
    }
    
    void DFS(unordered_map<int, vector<int>> &adj, int parent_node, int prev_node, vector<int>& result) {
        
        for(int &child : adj[parent_node]) {
            if(child == prev_node)
                continue;
            
            result[child] = result[parent_node] - count[child] + (N - count[child]);
            DFS(adj, child, parent_node, result);
        }
        
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        N = n;
        count.resize(n, 0);
        for(auto &vec : edges) {
            int u = vec[0];
            int v = vec[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        
        result_base_node = 0;
        
        dfsBase(adj, 0, -1, 0);
        
        vector<int> result(n, 0);
        
        result[0] = result_base_node;
        
        DFS(adj, 0, -1, result);
        
        return result;
    }
};


// Solution i thought but it's incorrect as 
    // cnt counts every neighbor of u, including its parent, so count[u] ends up being the degree of u. The re-rooting step needs count[u] to be the subtree size of u when the tree is rooted at 0.

    // The transition is:

    // res[child] = res[parent] - sub[child] + (n - sub[child])
    // The sub[child] nodes inside the child’s subtree get 1 closer.
    // The other n - sub[child] nodes get 1 farther.

    // With degrees instead of subtree sizes, the answers come out wrong. For example, on a path 0-1-2, node 1 has degree 2 but subtree size 2 only by coincidence, and node 2 has degree 1 and subtree size 1. A star or a deeper branching tree breaks it immediately.

    // Fix

    // Compute subtree sizes properly by processing the BFS order in reverse (children before parents). That also lets you avoid recursion, which matters since n goes up to 3·10⁴.
// class Solution {
// public:
//     vector<int> count;
//     int FBFS(vector<vector<int>>& adj, vector<bool>& visited){
//         int ds=0,lvl=0;
//         queue<int> q;
//         q.push(0);
//         visited[0]=true;
//         while(!q.empty()){
//             int sz=q.size();
//             ds+=(sz*lvl);
//             while(sz--){
//                 int u=q.front(); q.pop();
//                 int cnt=0;
//                 for(auto v:adj[u]){
//                     if(!visited[v]){
//                         visited[v]=true;
//                         q.push(v);
//                     }
//                     cnt++;
//                 }
//                 count[u]=cnt;
//             }
//             lvl++;
//         }
//         return ds;
//     }
//     void DFS(vector<vector<int>>& adj, int parent_node, int prev_node, vector<int>& res, int n) {
        
//         for(int &child : adj[parent_node]) {
//             if(child == prev_node)
//                 continue;
            
//             res[child] = res[parent_node] - count[child] + (n - count[child]);
//             DFS(adj, child, parent_node, res, n);
//         }
        
//     }

//     vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
//         vector<vector<int>> adj(n);
//         count.resize(n,0);
//         for(auto edge:edges){
//             int u=edge[0];
//             int v=edge[1];
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }
//         vector<bool> visited(n,false);
//         vector<int> res(n,0);
//         res[0]=FBFS(adj,visited);
//         DFS(adj,0,-1,res,n);
//         return res;
//     }
// };