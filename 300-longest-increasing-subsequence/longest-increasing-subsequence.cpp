class Solution {
public:
    // int solve(int i, int l_i, vector<int> &nums, vector<vector<int>> &dp){
    //     if(i >= nums.size()) return 0;
    //     if(dp[i][l_i+1] != -1) return dp[i][l_i+1];

    //     int not_take = solve(i+1, l_i, nums, dp);
    //     int take = INT_MIN;
    //     if(l_i == -1 || nums[i] > nums[l_i]){
    //         take = 1+solve(i+1, i, nums, dp);
    //     }

    //     return dp[i][l_i+1] = max(take, not_take);
    // }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int ans = 1;

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;;
    }
};