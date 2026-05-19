class Solution {
public:
    void bfs(int r, int c, vector<vector<int>>&ans, vector<vector<int>>& image, int ini_color, int newcolor){
        int dr[]={-1, 0, 1, 0};
        int dc[]={0, -1, 0, 1};
        ans[r][c]=newcolor;
        int n=ans.size();
        int m=ans[0].size();
        for(int i=0; i<4; i++){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(nr<n && nr>=0 && nc<m && nc>=0 && ans[nr][nc]!=newcolor && image[nr][nc]==ini_color){
                bfs(nr, nc, ans, image, ini_color, newcolor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int ini_color=image[sr][sc];
        vector<vector<int>>ans= image;
        bfs(sr, sc, ans, image, ini_color, color);
        return ans;
    }
};