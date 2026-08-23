class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &a, vector<vector<int>> &dp){
        if(a[i][j]==1) return dp[i][j]=0;
        if(i==0 && j==0) return dp[i][j]=1; 
        if(dp[i][j] != -1) return dp[i][j];
        int up=0, left=0;
        if(i-1>=0) up=solve(i-1, j, a, dp);
        if(j-1>=0) left=solve(i, j-1, a, dp);  
        return dp[i][j]=up+left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size(), m=obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        //return solve(n-1, m-1, obstacleGrid, dp);
        dp[0][0]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(obstacleGrid[i][j]==1){
                    dp[i][j]=0;
                    continue;
                }
                if(i==0 && j==0) continue;
                int up=0, left=0;
                if(i-1>=0) up=dp[i-1][j];
                if(j-1>=0) left=dp[i][j-1];
                dp[i][j]=left+up;
            }
        }
        return dp[n-1][m-1];
    }
};