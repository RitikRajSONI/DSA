class Solution {
public:
    bool checkBipartiteDFS(vector<vector<int>>& graph, int u, vector<int> &color, int curColor){
        color[u]=curColor;
        for(int &v:graph[u]){
            if(color[v]==color[u]) return false;
            if(color[v]==-1){
                int colorv=1-curColor;
                if(!checkBipartiteDFS(graph,v,color,colorv)) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V,-1);
        for(int i=0; i<V; i++){
            if(color[i]==-1){
                if(!checkBipartiteDFS(graph,i,color,1)) return false;
            }
        }
        return true;
    }
};