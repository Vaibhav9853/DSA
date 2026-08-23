class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];

        int prev = 0, prev2 = 0;
        int ans = 0;

        for(int i=0;i<n-1;i++){
            int temp = max(prev, prev2+nums[i]);
            prev2 = prev;
            prev = temp;
        }

        ans = max(prev, prev2);
        prev2 = 0;
        prev = 0;

        for(int i=1;i<n;i++){
            int temp = max(prev, prev2+nums[i]);
            prev2 = prev;
            prev = temp;
        }

        return max(ans, max(prev, prev2));
    }
};