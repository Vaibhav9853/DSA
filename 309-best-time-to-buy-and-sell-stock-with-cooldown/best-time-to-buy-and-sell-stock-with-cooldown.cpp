class Solution {
public:
    // int solve(int i, int buy, vector<int> &prices, vector<vector<int>> &dp){
    //     if(i >= prices.size()) return 0;
    //     if(dp[i][buy] != -1) return dp[i][buy];

    //     if(buy){
    //         return dp[i][buy] = max(-prices[i]+solve(i+1, 0, prices, dp), solve(i+1, 1, prices, dp));
    //     }
    //     else{
    //         return dp[i][buy] = max(prices[i]+solve(i+2, 1, prices, dp), solve(i+1, 0, prices, dp));
    //     }
    // }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int> (2, 0));

        for(int i=n-1;i>=0;i--){
            //can buy
            dp[i][1] = max(dp[i+1][0]-prices[i], dp[i+1][1]);
            //can sell
            dp[i][0] = max(dp[i+2][1]+prices[i], dp[i+1][0]);
        }
        return dp[0][1];
    }
};