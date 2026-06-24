class Solution {
public:
    int helper(vector<vector<int>>& grid, int r, int c, vector<vector<int>>& dp){
        if(r==0 && c==0){
            return grid[0][0];
        }
        if(r<0 || c<0)return 1e9;
        if(dp[r][c]!=-1)return dp[r][c];
        int left= grid[r][c]+helper(grid, r-1, c, dp);
        int up= grid[r][c]+helper(grid, r, c-1, dp);
        return dp[r][c]=min(up, left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n= grid[0].size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return helper(grid, m-1, n-1, dp);
    }
};