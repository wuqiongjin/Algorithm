class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        int sum = 0;
        for(auto e : nums)
            sum += e;
        int left = (sum + target) / 2;

        if(abs(target) > sum)
            return 0;
        if((sum + target) % 2 == 1) //根据二元一次方程组推导出来的
            return 0;

        vector<int> dp(left + 1, 0);//总和为left的背包，有dp[left]种数字组合方法
        dp[0] = 1;  //总和为0的背包，有1种放法，那就是什么都不放。  
                    //※注意※:这里放入的都是正数，因为你这里的left设定的是正数的那一堆数字，并不涉及负数
        for(int i = 0; i < nums.size(); ++i)
        {
            for(int j = left; j >= nums[i]; --j)
            {
                dp[j] += dp[j - nums[i]];   //理解不了一维的话，建议转化为二维dp去找规律
            }                               //每个元素都有选/不选 2种状态!
        }
        return dp[left];
    }
};