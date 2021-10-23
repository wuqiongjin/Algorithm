class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        //给其他位置初始化时，必须保证最终结果不会被初始化的值所影响，所以给了最大值
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for(int i = 0; i < coins.size(); ++i)
        {
            for(int j = coins[i]; j <= amount; ++j)
            {
                //如果前一个状态都没有元素能够组合出来，那么当前状态也组合不出来。
                //因为这里就是由前一个状态推导出来的。
                //ps:我们只需要考虑当前子状态如何推导当前状态。要摒弃全局的思路！
                if(dp[j - coins[i]] != INT_MAX)
                    dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }
        //这里表示没有组合能构成给定的金额
        if(dp[amount] == INT_MAX)
            return -1;
        return dp[amount];
    }
};