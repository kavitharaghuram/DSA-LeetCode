class Solution {
    int dir[4][2]={{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int R= grid.size();
        int C= grid[0].size();
        int area=0;
        for(int r=0; r<R; r++){
            for(int c=0; c<C; c++){
                if(grid[r][c]==1)area= max(area, bfs(grid, r, c));
            }
        }
        return area;
    }
    int bfs(vector<vector<int>>& grid, int r, int c){
        queue<pair<int, int>> q;
        q.push({r, c});
        grid[r][c]=0;
        int res=1;
        while(!q.empty()){
            auto node= q.front();
            q.pop();
            int row= node.first;
            int col= node.second;
            for(int i=0; i<4; i++){
                int nr= row+ dir[i][0];
                int nc= col+ dir[i][1];
                if(nr>=0 && nc>=0 && nr< grid.size()&& nc<grid[0].size()&& grid[nr][nc]==1){
                    res++;
                    q.push({nr, nc});
                    grid[nr][nc]=0;
                }
            }
        }
        return res;
    }
};