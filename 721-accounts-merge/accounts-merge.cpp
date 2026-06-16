class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int find(int node){
        if(parent[node]==node)return node;
        return parent[node]= find(parent[node]);
    }
    void unionbyrank(int u, int v){
        int pu= find(u);
        int pv= find(v);
        if(pu==pv)return;
        if(rank[pu]<rank[pv]){
            parent[pu]=pv;
            rank[pv]+=rank[pu];
        }
        else {
            parent[pv]=pu;
            rank[pu]+=rank[pv];
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n= accounts.size();
        parent.resize(n);
        rank.resize(n, 1);
        for(int i=0; i<n; i++)parent[i]=i;
        unordered_map<string, int> mapmailnode;
        for(int i=0; i<n; i++){
            for(int j=1; j<accounts[i].size(); j++){
                string mail= accounts[i][j];
                if(!mapmailnode.count(mail))mapmailnode[mail]=i;
                else unionbyrank(i, mapmailnode[mail]);
            }
        }
        vector<vector<string>>mergedMail(n);
        for(auto it: mapmailnode){
            string mail= it.first;
            int node= find(it.second);
            mergedMail[node].push_back(mail);
        }
        vector<vector<string>>ans;
        for(int i=0; i<n; i++){
            if(mergedMail[i].size()==0)continue;
            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it: mergedMail[i])temp.push_back(it);
            ans.push_back(temp);
        }
        return ans;
    }

};