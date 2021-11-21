class Solution {
public:
    //动态规划
    int maxProfit(vector<int>& prices) 
    {
        //dp[i][0]:表示第i天持有股票的最大利润
        //dp[i][1]:表示第i天不持有股票的最大利润        
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;

        for(int i = 1; i < prices.size(); ++i)
        {
            //dp[i][0]有2种来源:1.第i-1天也持有; 2.第i-1天不持有，然后在今天买入
            //dp[i][1]有2种来源:1.第i-1天不持有; 2.第i-1天持有，然后在今天卖出
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);//这里的dp[i-1][1]的值还可能留有上次买卖的利润
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
        }
        return dp[prices.size() - 1][1];
    }

    //贪心算法：因为次数是无数次，所以可以把一段区间的买卖交易转化为相邻2天的，然后把收益为'正'的加到profits上
    int maxProfit(vector<int>& prices) 
    {
        int profits = 0;
        for(int i = 1; i < prices.size(); ++i)
        {
            int tmp = prices[i] - prices[i - 1];
            if(tmp > 0)
                profits += tmp;
        }
        return profits;
    }
};