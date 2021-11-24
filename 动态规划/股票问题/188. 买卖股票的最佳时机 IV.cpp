class Solution {
public:
    int maxProfit(int k, vector<int>& prices) 
    {
        //和III的思路完全一致!
        if(k == 0 || prices.size() == 0)  return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(2 * k + 1, 0));
        //对第0天进行初始化
        for(int i = 1; i < 2 * k + 1; i += 2)
            dp[0][i] = -prices[0];

        for(int i = 1; i < prices.size(); ++i)
        {
            for(int j = 1; j < 2 * k + 1; ++j)
            {
                //奇数天买入; 偶数天卖出
                if(j % 2 == 1)
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i]);
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + prices[i]);
            }
        }
        //最后一次交易完毕一定是利润最大的
        return dp[prices.size() - 1][2 * k];
    }
};