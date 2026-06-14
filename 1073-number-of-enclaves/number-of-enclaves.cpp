class Solution {
public: 
    void dfs(int r, int c, vector<vector<int>>&grid, vector<vector<int>>&vis){
        int n= grid.size();
        int m= grid[0].size();
        vis[r][c]=1;
        int dr[]={-1, 0, 1, 0};
        int dc[]={0, -1, 0, 1};
        for(int i=0; i<4; i++){
            int nr= r+dr[i];
            int nc= c+dc[i];
            if(nr<n && nc<m && nr>=0 && nc>=0 && !vis[nr][nc] && grid[nr][nc]==1)dfs(nr, nc, grid, vis);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n= grid.size();//row
        int m= grid[0].size();//col
        vector<vector<int>>vis(n, vector<int>(m, 0));
        for(int i=0; i<m; i++){
             if(grid[0][i]==1 && !vis[0][i]){
                dfs(0,i, grid, vis);
             }
             if(grid[n-1][i]==1 && !vis[n-1][i]){
                dfs(n-1, i, grid, vis);
             }
        }
        for(int i=0; i<n; i++){
            if(grid[i][0]==1 && !vis[i][0]){
                dfs(i, 0, grid, vis);
            }
            if(grid[i][m-1]==1 && !vis[i][m-1]){
                dfs(i, m-1, grid, vis);
            }
        }
        int count=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    count++;
                }
            }
        }
        return count;
    }
};