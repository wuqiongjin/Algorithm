class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        //dp[i]: 从0~i之间，以i作为递增子序列的"结尾元素"的最长子序列长度为dp[i]
        //也就是说dp[nums.size() - 1]的值并不一定是最大的那个
        vector<int> dp(nums.size(), 1);
        int ans = 1;    //存放最长的递增子序列的长度

        for(int i = 1; i < nums.size(); ++i)
        {
            for(int j = 0; j <= i - 1; ++j)
            {
                if(nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            //找出dp数组中的最大值
            if(ans < dp[i]) 
                ans = dp[i];
        }
        return ans;
    }
};