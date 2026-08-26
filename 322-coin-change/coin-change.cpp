class Solution {
public:
    // int solve(int i, int amount, vector<int> &coins, vector<vector<int>> &dp){
    //     if(amount == 0) return 0;
    //     if(i == coins.size()) return 1e9;

    //     if(dp[i][amount] != -1) return dp[i][amount];

    //     int not_take = solve(i+1, amount, coins, dp);
    //     int take = 1e9;
    //     if(amount >= coins[i]) take = 1+solve(i, amount-coins[i], coins, dp);

    //     return dp[i][amount] = min(take, not_take);
    // }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int> (amount+1, 1e9));
        for(int i = 0; i < coins.size(); i++) dp[i][0] = 0;
        for(int j = coins[0]; j <= amount; j+=coins[0]) {
            dp[0][j] = j/coins[0];
        }
        
        for(int i=1;i<coins.size();i++){
            for(int j=0;j<=amount;j++){
                int not_take = dp[i-1][j];
                int take = 1e9;
                if(coins[i] <= j) take = 1+dp[i][j-coins[i]];

                dp[i][j] = min(take, not_take);
            }
        }
        
        if(dp[coins.size()-1][amount] >= 1e9) return -1;
        return dp[coins.size()-1][amount];
    }
};