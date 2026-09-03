class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> dp(n, 1);
        vector<int> par(n);
        for(int i=0;i<n;i++) par[i] = i;

        int maxLen = 1;
        int lastIdx = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    par[i] =  j;
                }
            }
            if(maxLen < dp[i]){
                maxLen = dp[i];
                lastIdx = i;
            }
        }

        vector<int> ans;
        while(par[lastIdx] != lastIdx){
            ans.push_back(nums[lastIdx]);
            lastIdx = par[lastIdx];
        }
        ans.push_back(nums[lastIdx]);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};