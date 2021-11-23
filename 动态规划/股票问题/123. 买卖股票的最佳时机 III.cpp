class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        ios::sync_with_stdio(false);
        cin.tie(0);

        //最多可以完成2笔交易，意味着我们可以买卖一次，也可以买卖二次，也可以全程不买。
        //对于每一天的状态，有5种情况: 
        //1. 没进行过任何操作
        //2. 进行过第一次买入   #可能是当天买入的，也可能是前几天买入的
        //3. 进行过第一次卖出
        //4. 进行过第二次买入
        //5. 进行过第二次卖出
        //dp[i][j]含义: 第i天j状态下的最大利润为dp[i][j]  j∈[0, 4]
        vector<vector<int>> dp(prices.size(), vector<int>(5, 0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[0][3] = -prices[0];  //我们可以在第一天就进行第2次买入操作!
        //注意:本题，可以在"同一天进行多次买卖"!!!

        //dp[i][1]的2种来源: 前一天就买入了dp[i - 1][1]; 前一天没买，今天买了dp[i - 1][0] - prices[i]
        for(int i = 1; i < prices.size(); ++i)
        {
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
            dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
        }
        //实际上，dp[prices.size() - 1][4]就是最大值. ->
        //假设股票一直在下跌，那么第一天就已经进行完了2次买卖，这就是最利润，也就是0. 此时也是dp[size()][4]最大
        //return dp[prices.size() - 1][4];
        return max({dp[prices.size() - 1][0], dp[prices.size() - 1][2], dp[prices.size() - 1][4]});
    }
};