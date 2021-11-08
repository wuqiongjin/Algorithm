class Solution {
public:
    int rob(vector<int>& nums) 
    {
        // vector<int> dp(nums.size(), 0);
        // if(nums.size() == 1)
        //     return nums[0];
        // if(nums.size() == 2)
        //     return max(nums[1], nums[0]);

        // dp[0] = nums[0];
        // dp[1] = nums[1];

        // for(int i = 2; i < nums.size(); ++i)
        // {
        //     if(i > 2)
        //         dp[i] = max(dp[i - 2] + nums[i], dp[i - 3] + nums[i]);
        //     else
        //         dp[i] = dp[i - 2] + nums[i];
        // }
        // return max(dp[nums.size() - 1], dp[nums.size() - 2]);

        //简洁版
        //dp[i]: 表示从 0 ~ i下标之间选取偷取的房间，所得到的钱数最大值是dp[i]
        vector<int> dp(nums.size(), 0);
        if(nums.size() == 1)    return nums[0];
        if(nums.size() == 2)    return max(nums[0], nums[1]);
        
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for(int i = 2; i < nums.size(); ++i)
        {
			//dp[i]的2种情况，dp[i-1]和dp[i - 2] + nums[i]
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        return dp[nums.size() - 1];
    }
};