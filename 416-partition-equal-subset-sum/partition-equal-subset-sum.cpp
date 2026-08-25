class Solution {
public:
    bool solve(int i, vector<int> &nums, vector<vector<int>> &dp, int sum){
        if(i==nums.size()) return sum==0;

        if(dp[i][sum] != -1) return dp[i][sum];

        bool not_take = solve(i+1, nums, dp, sum);
        bool take = false;
        if(sum >= nums[i]) take = solve(i+1, nums, dp, sum-nums[i]);

        return dp[i][sum] = take || not_take;
    }
    bool canPartition(vector<int>& nums) {
        int tot = accumulate(nums.begin(), nums.end(), 0);
        if(tot % 2 != 0) return false;
        
        int tar = tot/2;

        vector<vector<int>> dp(nums.size(), vector<int> (tar+1,-1));

        return solve(0, nums, dp, tar);
    }
};