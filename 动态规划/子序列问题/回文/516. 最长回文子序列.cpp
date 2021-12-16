class Solution {
public:
    //子序列 - 不连续
    //好好整理一下
    int longestPalindromeSubseq(string s) 
    {
        //区间dp
        //1. dp[i][j]: 字符串s在[i, j]范围内的最长回文子序列为dp[i][j]
        //2. 递推公式: 判断字符串是否是回文串，主要逻辑是判断 区间的端点字符s[i]与s[j]
        //当s[i] == s[j]时, dp[i][j] = dp[i + 1][j - 1] + 2;
        //解释: 状态dp[i][j]的两端已经相同了，那么"推出它的状态只能是dp[i + 1][j - 1]"，缩小两端区间-1的区间
        //当s[i] != s[j]时, dp[i][j]这个状态取决于舍弃区间两端的哪个端点
        //也就是dp[i][j] = max(d[i + 1][j], dp[i][j - 1])，从左区间+1和右区间-1中取得最大值
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        //3. 初始化
        //dp数组如何初始化主要看递推公式的边界取值
        //递推公式中没有
        for(int i = 0; i < s.size(); ++i)
            dp[i][i] = 1;
        
        for(int i = s.size() - 1; i >= 0; --i)
        {
            for(int j = i + 1; j < s.size(); ++j)
            {
                if(s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[0][s.size() - 1];
    }
};