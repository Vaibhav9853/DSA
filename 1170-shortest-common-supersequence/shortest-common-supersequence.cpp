class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();

        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        string common = "";
        int i=m,j=n;
        while(i>=1 && j>=1){
            if(s1[i-1]==s2[j-1]){
                common += s1[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                i--;
            }
            else j--;
        }

        reverse(common.begin(), common.end());

        string ans = "";
        i=0,j=0;
        for(char ch:common){
            while(s1[i]!=ch){
                ans+=s1[i];
                i++;
            }
            while(s2[j]!=ch){
                ans+=s2[j];
                j++;
            }
            ans += ch;
            i++;
            j++;
        }
        while(i<m) {ans+=s1[i]; i++;}
        while(j<n) {ans+=s2[j]; j++;}

        return ans;
    }
};