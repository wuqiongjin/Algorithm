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


//N-2
class Solution {
public:
    int integerBreak(int n) {
        //dp[j]: 拆分数字j, 可以得到的最大成乘积化为dp[j]
        //dp[j]可以由2种情况拆分: 1.直接拆分为2个数字的积 2.拆分为一个数字和另一个dp(子问题)
        //dp[j] = max(i * (j - i), i * dp[j - i]);
        vector<int> dp(n + 1);
        dp[0] = 0;
        dp[1] = 1;

        for(int j = 2; j <= n; ++j)
        {
            for(int i = 1; i < j; ++i)
            {
                dp[j] = max({dp[j], i * (j - i), i * dp[j - i]});
            }
        }
        return dp[n];
    }
};