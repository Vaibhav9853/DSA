class Solution {
public:
    int solve(int i, int buy, vector<int> &prices, int t, vector<vector<vector<int>>> &dp){
        if(t == 2) return 0;
        if(i == prices.size()-1){
            if(buy == 1){
                return dp[i][buy][t] = prices[i];
            }
            else return dp[i][buy][t] = 0;
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
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (2, -1)));
        return solve(0, 0, prices, 0, dp);
    }
};