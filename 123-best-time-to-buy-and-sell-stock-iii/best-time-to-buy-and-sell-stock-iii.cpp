class Solution {
public:
    int solve(int i, int buy, vector<int> &prices, int t, vector<vector<vector<int>>> &dp){
        if(t == 2) return 0;
        if(i == prices.size()){
            return 0;
        }
        if(dp[i][buy][t] != -1) return dp[i][buy][t];

        if(buy){
            return dp[i][buy][t] = max(prices[i] + solve(i+1, 0, prices, t+1, dp), solve(i+1, buy, prices, t, dp));
        }
        else{
            return dp[i][buy][t] = max(solve(i+1, 1, prices, t, dp)-prices[i], solve(i+1, buy, prices, t, dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3, 0)));

        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=2;j++){
                //can buy
                dp[i][1][j] = max(dp[i+1][0][j]-prices[i], dp[i+1][1][j]);
                //hold
                dp[i][0][j] = max(dp[i+1][1][j-1]+prices[i], dp[i+1][0][j]);
            }
        }
        return dp[0][1][2];
    }
};