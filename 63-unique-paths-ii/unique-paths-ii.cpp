class Solution {
public:
    int helper(vector<vector<int>>& obstacleGrid, int r, int c, vector<vector<int>>& dp){
        int n= obstacleGrid.size();
        int m= obstacleGrid[0].size();
        if(r<0 || c<0)return 0;
        if(obstacleGrid[r][c]==1)return 0;
        if(r==0 && c==0)return 1;
        if(dp[r][c]!=-1)return dp[r][c];
        int up=helper(obstacleGrid, r-1, c, dp);
        int left=helper(obstacleGrid, r, c-1, dp);
        return dp[r][c]=up+left;
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m= obstacleGrid.size();
        int n= obstacleGrid[0].size();
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return helper(obstacleGrid, m-1, n-1, dp);
    }
};