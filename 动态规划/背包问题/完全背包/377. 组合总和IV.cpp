class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) 
    {
        //错了，这里是排列，并不算组合。即 1 1 2 和 1 2 1是不同的
        //\ 0 1 2 3 4
        //1 1 1 1 1 1
        //2 1 1 2 2 3
        //3 1 1 2 3 4
        //ps:上面的图是错的

        //求排列：先遍历背包容量，再遍历物品
        //求组合：先遍历物品，再遍历背包容量
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for(int j = 0; j <= target; ++j)
        {
            for(int i = 0; i < nums.size(); ++i)
            {
                //对溢出的数做处理，因为本题的返回值是int，所以不用考虑如何返回溢出的值。
                if(j >= nums[i] && dp[j] < INT_MAX - dp[j - nums[i]])//这里只能这么判断，要用INT_MAX - 一个数，而不能用两个数加起来和INT_MAX做判断
                    dp[j] += dp[j - nums[i]];
            }
        }
        return dp[target];
    }
};