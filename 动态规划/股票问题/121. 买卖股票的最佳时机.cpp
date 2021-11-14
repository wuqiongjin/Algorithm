class Solution {
public:
    //1.
    //dp[i][0]:表示第i天持有股票的的状态下 的最大利润(最多现金)是dp[i][0]
    //dp[i][1]:表示第i天已经卖出股票的状态下 的最大利润(最多现金)是dp[i][1]
    int maxProfit(vector<int>& prices) 
    {
        if(prices.size() == 1)  return 0;
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        dp[0][0] -= prices[0];  //表示第一天买入了股票，所以 -= prices[0]
        dp[0][1] = 0;           //第一天不买股票，所以利润是0

        for(int i = 1; i < prices.size(); ++i)
        {
            //dp[i][0]的2种状态:
            //第i - 1天已经持有股票了
            //第i 天买入该股票，所以是 -prices[i]   #买入股票之前利润是0
            dp[i][0] = max(dp[i - 1][0],  -prices[i]);

            //dp[i][1]的2种状态:
            //第i - 1天就已经卖出股票了
            //第i 天卖出股票，所以要 "用前一天持有股票的状态" + prices[i]
            dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i - 1][0]);
        }
        return dp[prices.size() - 1][1];
    }
};


//2. 另一种思路的dp，比较简单

// class Solution {
// public:
//     int maxProfit(vector<int>& prices)
//     {
//         if(prices.size() == 1)  return 0;
//         //dp[i]: 从[0, i - 1]天选取股票的最小价格进行购买，
//         //并在[0, i]天中进行卖出的最大利润是dp[i]
//         vector<int> dp(prices.size(), 0);   //dp数组初始化为0
        
//         //用一个变量tmp存储[0, i]天中的最小价格
//         int tmp = prices[0];
//         for(int i = 1; i < prices.size(); ++i)
//         {
//             if(prices[i] < tmp)
//                 tmp = prices[i];
//             dp[i] = max(dp[i - 1], prices[i] - tmp);
//         }
//         return dp[prices.size() - 1];
//     }
// };