class Solution {
public:
    //动态规划
    //dp[i]:
    //dp[i] <---  dp[i-1] + nums[i]
    //      <---  nums[i]
    //dp[i] = max(nums[i], dp[i-1] + nums[i]);
    int maxSubArray(vector<int>& nums) 
    {
        if(nums.size() == 0)    return nums[0];
        //dp[i]: 从[0, i]且包含下标i，的最大连续子数组的和为dp[i]
        //由于dp数组包含了包含了下标i，所以最大连续子数组的和不一定是dp[nums.size() - 1]!!! 因为最大值不一定包含i
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int ans = nums[0];  //用来记录最大连续子数组的和

        for(int i = 1; i < nums.size(); ++i)
        {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            if(ans < dp[i]) ans = dp[i];
        }
        return ans;
    }
};



// class Solution {
// public:
//     //贪心算法
//     int maxSubArray(vector<int>& nums) 
//     {
//         int ans = nums[0], sum = 0;
//         for(int i = 0; i < nums.size(); ++i)
//         {
//             sum += nums[i];
//             //ans记录最大和
//             if(sum > ans)
//                 ans = sum;
            
//             //如果sum是负的，那么将其重置为0。也就是舍弃之前的组合之和。（因为负数 + 任何数都会变小）
//             if(sum < 0)
//                 sum = 0;
//         }
//         return ans;
//     }
// };