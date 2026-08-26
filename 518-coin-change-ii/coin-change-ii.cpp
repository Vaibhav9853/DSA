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
    int change(int amount, vector<int>& coins) {
        vector<vector<unsigned int>> dp(coins.size(), vector<unsigned int> (amount+1, 0));
        for(int i = 0; i < coins.size(); i++) dp[i][0] = 1;
        for(int j = coins[0]; j <= amount; j+=coins[0]) {
            dp[0][j] = 1;
        }
        
        for(int i=1;i<coins.size();i++){
            for(int j=0;j<=amount;j++){
                unsigned int not_take = dp[i-1][j];
                unsigned int take = 0;
                if(coins[i] <= j) take = dp[i][j-coins[i]];

                dp[i][j] = take + not_take;
            }
        }
        
        return dp[coins.size()-1][amount];
    }
};