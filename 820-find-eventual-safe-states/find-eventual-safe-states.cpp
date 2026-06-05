class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<vector<int>>adjRev(V);
        //v->u
        vector<int>indegree(V, 0);
        for(int i=0; i<V; i++){
          for(auto neighbour : graph[i]){
             adjRev[neighbour].push_back(i);
             indegree[i]++;
            }
        }
        queue<int>q;
        for(int i=0; i<V; i++){
            if(indegree[i]==0)q.push(i);
        }
        vector<int>safe;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            safe.push_back(node);
            for(auto it: adjRev[node]){
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }
        }
        sort(safe.begin(), safe.end());
        return safe;
    }
};