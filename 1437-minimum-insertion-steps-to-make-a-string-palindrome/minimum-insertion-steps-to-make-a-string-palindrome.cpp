class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));

        for(int i=1;i<=n;i++){
            for(int j=n;j>=1;j--){
                if(s[i-1]==s[j-1]){
                    dp[i][n-j+1] = 1+dp[i-1][n-j];
                }
                else{
                    dp[i][n-j+1] = max(dp[i-1][n-j+1], dp[i][n-j]);
                }
            }
        }

        int rem = n-dp[n][n];
        return rem;
    }
};