class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int fresh=0;
        int time=0;
        for(int r=0; r<grid.size(); r++){
            for(int c=0; c<grid[0].size(); c++){
                if(grid[r][c]==1)fresh++;
                if(grid[r][c]==2)q.push({r, c});
            }
        }
        vector<vector<int>> dir={{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        while(fresh>0 && !q.empty()){
            int size= q.size();
            for(int i=0; i<size; i++){
                int row= q.front().first;
                int col= q.front().second;
                q.pop();
                for(int j=0; j<4; j++){
                    int r= row+ dir[j][0];
                    int c= col+ dir[j][1];
                    if(r>=0 && c>=0 && r< grid.size()&& c<grid[0].size()&& grid[r][c]==1){
                        grid[r][c]=2;
                        fresh--;
                        q.push({r, c});
                    }
                }
            }
            time++;
        }
        return fresh==0? time: -1;
    }
};