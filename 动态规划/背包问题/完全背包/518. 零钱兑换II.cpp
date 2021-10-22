class Solution {
public:
    int change(int amount, vector<int>& coins) 
    {
        //本题的递推公式求法和目标和的求解方法类似，
        //dp[j]：背包大小为j的背包，填满背包的组合方法有dp[j]种 ##“组合”和“排列” 要注意区分
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;

        //完全背包:物品由于是无限取的，因此我们遍历背包时要正向遍历，
        //这样能保证每一次取完之后，下一次取仍可能取到已经被取到的物品
        for(int i = 0; i < coins.size(); ++i)
        {
            for(int j = coins[i]; j <= amount; ++j)
            {
                dp[j] = dp[j] + dp[j - coins[i]];
            }
        }
        return dp[amount];
    }
};