class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses, 0);
        for(auto pre: prerequisites){
            adj[pre[1]].push_back(pre[0]);
        }
        for(int i=0; i<numCourses; i++){
            for(auto nei: adj[i]){
                indegree[nei]++;
            }
        }
        queue<int>q;
        for(int i=0; i<numCourses; i++){
            if(indegree[i]==0)q.push(i);
        }
        vector<int>topo;
        while(!q.empty()){
            int node= q.front();
            topo.push_back(node);
            q.pop();
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }
        }
        if(topo.size()==numCourses)return topo;
        return {};
    }
};