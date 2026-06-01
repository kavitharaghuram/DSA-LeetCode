//anyone that has incoming edges connecting to a cycle or a cycle itself- not safe
class Solution {
public:
    bool dfsCheck(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis, vector<int>& check){
        check[node]=0;
        vis[node]=1;
        pathVis[node]=1;
        for(auto it: adj[node]){
            if(!vis[it] && !pathVis[it]){
                check[node]=0;
                if(dfsCheck(it, adj, vis, pathVis, check)==true)return true;
            }
            else if(pathVis[it]){
                check[node]=0;
                return true;
            }
        }
        pathVis[node]=0;
        check[node]=1;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V= graph.size();
        vector<int>vis(V, 0);
        vector<int>pathVis(V, 0);
        vector<int>check(V, 0);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfsCheck(i, graph, vis, pathVis, check);
            }
        }
        vector<int>res;
        for(int i=0; i<V; i++){
            if(check[i]==1){
                res.push_back(i);
            }
        }
        return res;
    }
};