class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        //dp[i][j]: 所有A[0~i]和B[0~j]的最长公共子序列的长度为dp[i][j]
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        for(int i = 1; i <= text1.size(); ++i)
        {
            for(int j = 1; j <= text2.size(); ++j)
            {
                //A[i]和B[j]相等时, 就转化为了A[0~i-1]和B[0~j-1]的最长公共子序列的长度 + 1了
                if(text1[i - 1] == text2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else//3种状态: A[i]存在但是和B[j]不同,A[i]不存在、B[j]存在,A[i]存在、B[j]不存在
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    //后两种就是dp[i - 1][j]和dp[i][j - 1].它们都包含了第一种
            }
        }
        return dp[text1.size()][text2.size()]; 
    }
};