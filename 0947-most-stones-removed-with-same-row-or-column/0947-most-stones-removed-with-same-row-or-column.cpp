class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if(parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);


        if(rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if(rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0; i<n; i++) parent[i]=i;
        for(int i=0; i<n; i++){
            int x=stones[i][0];
            int y=stones[i][1];
            for(int j=i+1; j<n; j++){
                int x_=stones[j][0];
                int y_=stones[j][1];
                if((x_==x || y_==y) && find(i)!=find(j)){
                    Union(i,j);
                }
            }
        }
        int groups =0;
        for(int i=0; i<n; i++){ 
            if(parent[i]==i) groups++;
        }

        return n-groups;
    }
};