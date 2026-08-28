class Solution {
public:
    int maxProfit(int m, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (m+1, 0)));
        for(int i=n-1;i>=0;i--){
            for(int k=1;k<=m;k++){
                // can buy
                dp[i][1][k] = max(
                    dp[i+1][0][k] - prices[i],
                    dp[i+1][1][k]
                );

                // holding stock
                dp[i][0][k] = max(
                    dp[i+1][1][k-1] + prices[i],
                    dp[i+1][0][k]
                );
            }
        }
        return dp[0][1][m];
    }
};