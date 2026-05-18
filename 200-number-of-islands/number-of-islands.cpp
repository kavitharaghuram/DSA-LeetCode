class Solution {
public: 
    void bfs(int row, int col, vector<vector<int>>&vis, vector<vector<char>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int, int>> q;
        q.push({row, col});
        vis[row][col]=1;
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            int dr[]={-1, 1, 0, 0};
            int dc[]={0, 0, -1, 1};
              for(int i=0; i<4; i++){
                    int nr=r+dr[i];
                    int nc=c+dc[i];
                    if(nr<n && nr>=0 && nc<m && nc>=0 && !vis[nr][nc]&& grid[nr][nc]=='1'){
                        vis[nr][nc]=1;
                        q.push({nr, nc});
                    }
                }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int count=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    bfs(i, j, vis, grid);
                    count++;
                }
            }
        }
        return count;
    }
};