class Solution {
public:
    // int solve(int i, int j, string s1, string s2, vector<vector<int>> &dp){
    //     if(i==s1.size() || j==s2.size()) return 0;
    //     if(dp[i][j] != -1) return dp[i][j];

    //     if(s1[i] == s2[j]){
    //         return dp[i][j] = 1+solve(i+1, j+1, s1, s2, dp);
    //     }
    //     else{
    //         return dp[i][j] = max(solve(i+1, j, s1, s2, dp), solve(i, j+1, s1, s2, dp));
    //     }
    // }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1, vector<int> (text2.size()+1, 0));

        for(int i=1;i<=text1.size();i++){
            for(int j=1;j<=text2.size();j++){
                if(text1[i-1] == text2[j-1]) dp[i][j] = 1+dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[text1.size()][text2.size()];
    }
};