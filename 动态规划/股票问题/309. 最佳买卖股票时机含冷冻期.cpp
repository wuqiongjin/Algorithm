class Solution {
public:
    //我这里设了4个状态, 对应二维dp的j位置下标
    int maxProfit(vector<int>& prices) 
    {
                                    //这里的昨天就没操作包含"全程都不操作!"
        //0: 不进行任何操作 (分2种情况: 昨天就没操作;  昨天是冷冻期(前天卖出了股票), 今天没进行任何操作)
        //1: 买入股票, 持有股票 (3个来源: 昨天就是持有状态;  昨天是冷冻期,今天买入股票;  昨天没操作,今天买入股票)
        //2: 今天卖出股票 (+ prices[i])(只有1天) (昨天只可能是买入状态)
        //3: 今天是冷冻期              (只有1天) (昨天只可能是卖出状态)
        vector<vector<int>> dp(prices.size(), vector<int>(4, 0));
        dp[0][1] = -prices[0];

        for(int i = 1; i < prices.size(); ++i)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][3]);
            dp[i][1] = max({dp[i - 1][1], dp[i - 1][3] - prices[i], dp[i - 1][0] - prices[i]});
            dp[i][2] = dp[i - 1][1] + prices[i];
            dp[i][3] = dp[i - 1][2];
        }
        return max({dp[prices.size() - 1][0], dp[prices.size() - 1][2], dp[prices.size() - 1][3]});
    }
};

//Carl哥的
//class Solution {
// public:
//     int maxProfit(vector<int>& prices) 
//     {
//         //我们将股票的买卖分为4种状态:
//         //0下标表示买入股票
//         //1下标表示2天或更早之前卖出了股票，渡过了冷冻期
//         //2下标表示今天卖出了股票
//         //3下标表示冷冻期
//         vector<vector<int>> dp(prices.size(), vector<int>(4, 0));
//         dp[0][0] = -prices[0];
//         //第一天的剩下的所有状态下的dp值都是0

//         for(int i = 1; i < prices.size(); ++i)
//         {
//             dp[i][0] = max({dp[i - 1][0], dp[i - 1][1] - prices[i], dp[i - 1][3] - prices[i]});
//             dp[i][1] = max(dp[i - 1][1], dp[i - 1][3]);
//             dp[i][2] = dp[i - 1][0] + prices[i];
//             dp[i][3] = dp[i - 1][2];
//         }
//         return max({dp[prices.size() - 1][1], dp[prices.size() - 1][2], dp[prices.size() - 1][3]});
//     }
// };