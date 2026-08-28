class Solution {
public:
    int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
        if(i==s1.size()) return s2.size()-j;
        if(j==s2.size()) return s1.size()-i;
        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]){
            return dp[i][j] = solve(i+1, j+1, s1, s2, dp);
        }
        else{
            int y = 1+solve(i,j+1,s1,s2,dp);
            int z = 1+solve(i+1,j,s1,s2,dp);
            int w = 1+solve(i+1,j+1,s1,s2,dp);

            return dp[i][j] = min(y, min(z,w));
        }
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size(), vector<int> (word2.size(), -1));
        return solve(0,0,word1,word2,dp);
    }
};