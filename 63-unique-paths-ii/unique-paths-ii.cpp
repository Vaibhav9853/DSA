class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        int m = obs.size();
        int n = obs[0].size();
        if(obs[0][0] == 1) return 0;
        vector<int> dp(n,0);
        for(int i=0;i<n;i++){
            if(obs[0][i] == 1){
                dp[i] = 0;
                break;
            }
            else dp[i] = 1;
        }

        for(int i=1;i<m;i++){
            if(obs[i][0] == 1) dp[0] = 0;
            for(int j=1;j<n;j++){
                if(obs[i][j] == 1) dp[j] = 0;
                else dp[j] = dp[j] + dp[j-1];
            }
        }

        return dp[n-1];
    }
};