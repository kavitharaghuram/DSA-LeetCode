class Solution {
public:
unordered_map<int, vector<int>> premap;
unordered_set<int> visited;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i=0; i<numCourses; i++){
            premap[i]={};
        }
        for(const auto& prereq: prerequisites){
            premap[prereq[0]].push_back(prereq[1]);
        }
        for(int c=0; c<numCourses; c++){
            if(!dfs(c))return false;
        }
        return true;
    }
    bool dfs(int course){
        if(visited.count(course))return false; //cycle detected
        if(premap[course].empty())return true;
        visited.insert(course);
        for(int pre: premap[course]){
            if(!dfs(pre))return false;
        }
        visited.erase(course);
        premap[course].clear();
        return true;
    }
};