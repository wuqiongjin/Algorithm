class Solution {
public:
    int integerBreak(int n) 
    {
        vector<int> dp(n + 1);
        dp[2] = 1;

        //j * dp[i - j]代表 i被拆分为了 j + dp[i - j]中的拆分析(也可能有好多项)
        for(int i = 3; i <= n; ++i)
        {
            for(int j = i - 1; j > 0; --j)
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));   
                 //这里还要加dp[i]的意义在于，存储上一次 j值下的拆分结果 来和 这一次的拆分结果进行比较
        }
        return dp[n];
    }
};