class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int> (2, 0));
        int sell = 0, buy = 0;
        for(int i=n-1;i>=0;i--){
            //can buy
            buy = max(sell-prices[i], buy);
            //can sell
            sell = max(buy+prices[i]-fee, sell);
        }

        return buy;
    }
};