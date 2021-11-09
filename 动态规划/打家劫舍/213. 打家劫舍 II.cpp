class Solution {
public:
    int _rob(const vector<int>& nums, int start, int end)
    {
        vector<int> dp(end + 1, 0);
        dp[start] = nums[start];
        dp[start + 1] = max(nums[start], nums[start + 1]);

        for(int i = start + 2; i <= end; ++i)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[end];
    }

    int rob(vector<int>& nums) 
    {
        if(nums.size() == 1)    return nums[0];
        if(nums.size() == 2)    return max(nums[0], nums[1]);

        //因为本题是环状房子，我们可以通过对比 [0 ~ n - 1] 与 [1 ~ n]，这样就不需要考虑环状的因素了
        int ans1 = _rob(nums, 0, nums.size() - 2);
        int ans2 = _rob(nums, 1, nums.size() - 1);

        return max(ans1, ans2);
    }
};