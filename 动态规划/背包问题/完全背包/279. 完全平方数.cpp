class Solution {
public:
    int numSquares(int n) 
    {
        //经典的 完全背包题
        //本题求的是组合数
        vector<int> dp(n + 1, INT_MAX); //初始值必须足够大，这样才能在递推过程中覆盖掉初值
        dp[0] = 0;  //dp[1] = dp[0] + 1; 所以给dp[0]赋值为0比较合适。
        //先遍历物品/先遍历背包都可以。这里就先遍历物品了。不过物品的所代表的价值要用tmp*tmp表示
        for(int i = 1, tmp = 1; i <= n; ++tmp, i = tmp * tmp)
        {
            for(int j = i; j <= n; ++j)
            {
                dp[j] = min(dp[j], dp[j - i] + 1);
            }
        }
        return dp[n];
    }
};