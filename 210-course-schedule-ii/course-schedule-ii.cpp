class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> prereq;
        vector<int> output;
        for(const auto& pair: prerequisites){
            prereq[pair[0]].push_back(pair[1]);
        }
            unordered_set<int>visit;
            unordered_set<int>cycle;
            for(int c=0; c<numCourses; c++){
                if(!dfs(c, prereq, visit, cycle, output))return {};
            }
        return output;
    }
    bool dfs(int c, unordered_map<int, vector<int>>&prereq, unordered_set<int> &visit, unordered_set<int> &cycle, vector<int>& output){
        if(cycle.count(c))return false;
        if(visit.count(c))return true;
        cycle.insert(c);
        if(prereq.count(c)){
            for(int pre: prereq[c]){
                if(!dfs(pre, prereq, visit, cycle, output))return false;
            }
        }
        cycle.erase(c);
        visit.insert(c);
        output.push_back(c);;
        return true;
    }
};