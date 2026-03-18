class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int N= grid.size();
        set<pair<int, int>> visit;
        priority_queue<vector<int>, vector<vector<int>>, greater<>> minH;
        vector<vector<int>> dir={{0,1}, {0, -1}, {1, 0}, {-1, 0}};
        minH.push({grid[0][0], 0, 0});
        visit.insert({0, 0});
        while(!minH.empty()){
            auto curr= minH.top();
            minH.pop();
            int t= curr[0], r=curr[1], c= curr[2];
            if(r==N-1 && c== N-1)return t;
            for(const auto &d: dir){
                int neiR= r+ d[0];
                int neiC= c+ d[1];
                if(neiR<0 || neiC <0 || neiR== N || neiC==N || visit.count({neiR, neiC}))continue;
                visit.insert({neiR, neiC});
                minH.push({max(t, grid[neiR][neiC]), neiR, neiC});
            }

        }
        return N*N;
    }
};