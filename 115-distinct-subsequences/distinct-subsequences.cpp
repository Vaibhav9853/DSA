class Solution {
public:
    // int solve(string &s, string &t, int i, int j, vector<vector<int>> &dp){
    //     if(j == t.size()) return 1;
    //     if(i >= s.size()) return 0;
    //     if(dp[i][j] != -1) return dp[i][j];

    //     int not_take = solve(s,t,i+1,j,dp);
    //     int take = 0;
    //     if(t[j] == s[i]) take = solve(s,t,i+1,j+1,dp);

    //     return dp[i][j] = take + not_take;
    // }
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();

        vector<unsigned int> dp(n+1,0);
        dp[0] = 1;

        for(int i=1;i<=m;i++){
            for(int j=min(i,n);j>=1;j--){
                unsigned int not_take = dp[j];
                unsigned int take = 0;
                if(s[i-1] == t[j-1]) take = dp[j-1];

                dp[j] = take + not_take; 
            }
        }
        return dp[n];
    }
};