class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) 
    {
        //这题的dp数组还是只有2种状态
        //我们设dp[i][0]:买入, dp[i][1]:卖出
        //dp[i][0]有2个来源: 昨天就已经买入了; 今天刚买入
        //dp[i][1]有2个来源: 昨天就已经卖出了; 今天卖出
        //唯一需要注意的是费用，利润不能为负，所以在卖出的时候要和0进行比较，如果比0小就舍弃当天的价格
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp[0][0] = -prices[0];

        for(int i = 1; i < prices.size(); ++i)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max({0, dp[i - 1][1], dp[i - 1][0] + prices[i] - fee});
        }
        return dp[prices.size() - 1][1];
    }
};