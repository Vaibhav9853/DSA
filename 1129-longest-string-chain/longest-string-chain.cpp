class Solution {
public:
    static bool comp(string& s1, string &s2){
        return s1.size()<s2.size();
    }
    bool check(string &s1, string &s2){
        if(s2.size() != s1.size() + 1) return false;
        
        int i=0, j=0;
        int cnt = 0;
        while(i<s1.size() && j<s2.size()){
            if(s1[i] == s2[j]){
                i++;
                j++;
            }
            else{
                cnt++;
                j++;
                if(cnt > 1){
                    return false;
                }
            }
        }
        return true;
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), comp);

        vector<int> dp(n, 1);
        int ans = 1;

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(check(words[j], words[i])){
                    dp[i] = max(dp[i], 1+dp[j]);
                    ans = max(ans, dp[i]);
                }
            }
        }

        return ans;
    }
};