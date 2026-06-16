class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n= edges.size();
        vector<int>par(n+1), rank(n+1, 1);
        for(int i=0; i<=n; i++){
            par[i]=i;
        }
        for (const auto& edge : edges){
            if(!unionofsets(par, rank, edge[0], edge[1]))return {edge[0], edge[1]};
        }
        return {};
    }
    int find(vector<int>&par, int x){
        if(par[x]==x)return x;
        return par[x]=find(par, par[x]);
    }
    bool unionofsets(vector<int>& par, vector<int>& rank, int e1, int e2){
        int p1= find(par, e1);
        int p2= find(par, e2);
        if(p1==p2)return false;
        if(rank[p1]>rank[p2]){
            par[p2]=p1;
            rank[p1]+=rank[p2];
        }
        else {
            par[p1]=p2;
            rank[p2]+=rank[p1];
        }
        return true;
    }
};