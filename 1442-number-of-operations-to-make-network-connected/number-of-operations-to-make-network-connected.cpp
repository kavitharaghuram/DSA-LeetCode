class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int>par(n);
        vector<int>rank(n);
        for(int i=0; i<n; i++)par[i]=i;
        int extra=0;
        for(const auto& connect: connections){
            if(!unionbyrank(rank, par, connect[0], connect[1]))extra++;
        }
        int cntc=0;
        for(int i=0; i<n; i++)if(par[i]==i)cntc++;
        if(extra>=cntc-1)return cntc-1;
        return -1;
    }
    int find(vector<int>&par, int x){
        if(par[x]==x)return x;
        return par[x]=find(par, par[x]);
    }
    bool unionbyrank(vector<int>&rank, vector<int>& par, int c1, int c2){
        int p1= find(par, c1);
        int p2= find(par, c2);
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