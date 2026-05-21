class Solution {
public:
    void dfs(int r, int c, vector<vector<char>>& board, vector<vector<int>>& vis){
        int n= board.size();
        int m=board[0].size();
        vis[r][c]=1;
        int dr[]={-1, 0, 1, 0};
        int dc[]={0, -1, 0,1};
        for(int i=0; i<4; i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr<n && nc<m && nr>=0 && nc>=0 && board[nr][nc]=='O' && !vis[nr][nc]){
                vis[nr][nc]=1;
                dfs(nr, nc, board, vis);
            }
            
        }
    }
    void solve(vector<vector<char>>& board) {
        int n= board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i=0; i<m; i++){
            if(!vis[0][i] && board[0][i]=='O'){
                dfs(0, i, board, vis);
            }
            if(!vis[n-1][i] && board[n-1][i]=='O'){
                dfs(n-1, i, board, vis);
            }
        }
        for(int i=0; i<n; i++){
            if(!vis[i][0] && board[i][0]=='O'){
                dfs(i, 0, board, vis);
            }
            if(!vis[i][m-1] && board[i][m-1]=='O'){
                dfs(i, m-1, board, vis);
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j]&& board[i][j]=='O')board[i][j]='X';
            }
        }
    }
};