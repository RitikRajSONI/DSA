class Solution {
public:
    void BFS(unordered_map<int,vector<int>>& adj, int n, int cur, int& st, int& dist){
        vector<bool> visited(n, false);   // n instead of adj.size()
        queue<int> q;
        q.push(cur);
        visited[cur] = true;
        int lvl = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int u = q.front(); q.pop();
                st = u;
                for(auto v : adj[u]){
                    if(!visited[v]){
                        q.push(v);
                        visited[v] = true;
                    }
                }
            }
            lvl++;
        }
        dist = lvl - 1;
    }

    int findMXD(unordered_map<int,vector<int>>& adj, int n){   // by reference
        int dist = 0;
        int st = 0;
        BFS(adj, n, 0, st, dist);
        BFS(adj, n, st, st, dist);
        return dist;
    }

    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n1 = edges1.size() + 1;
        int n2 = edges2.size() + 1;
        unordered_map<int,vector<int>> adj1, adj2;
        for(auto& edge : edges1){
            adj1[edge[0]].push_back(edge[1]);
            adj1[edge[1]].push_back(edge[0]);
        }
        for(auto& edge : edges2){
            adj2[edge[0]].push_back(edge[1]);
            adj2[edge[1]].push_back(edge[0]);
        }

        int d1 = findMXD(adj1, n1);
        int d2 = findMXD(adj2, n2);
        return max({d1, d2, (d1 + 1) / 2 + (d2 + 1) / 2 + 1});
    }
};