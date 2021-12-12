class Solution {
public:
    int minDistance(string word1, string word2) 
    {
        //本题的dp稍微有点绕
        //dp[i][j]: 以i-1为结尾的word1和以j-1为结尾的word2，想要达到相同所需要的最小删除次数为dp[i][j]次
        //状态转移方程:
        //分析状态: 本题依然是2种状态，结尾字符相等和不相等
        //当word1[i - 1] == word2[j - 1]
        //dp[i][j] = dp[i - 1][j - 1]
        //当word1[i - 1] != word2[j - 1]
        //dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 2})
        //针对不相等的情况，我们可以具体的分析👇↓↓↓
        //本题的特点就是可以对2个字符串都进行"删除的操作"
        //因此在分析word1[i - 1] != word2[j -1]时，要考虑删除不同字符串的情况
        //这里一共有3种情况:
        //1. 删除word1[i - 1]       --> 算作1步
        //2. 删除word2[j - 1]       --> 算作1步
        //3. 删除word1[i - 1]和word2[j - 1] -->算作2步
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1));
        //初始化
        //根据状态转移方程去找边界，边界就是dp[i][0]和dp[0][i]
        //考虑dp[i][0]代表什么意思
        //考虑dp[0][i]代表什么意思
        dp[0][0] = 0;
        for(int i = 1; i <= word1.size(); ++i)
            dp[i][0] = i;
        for(int i = 1; i <= word2.size(); ++i)
            dp[0][i] = i;
        
        //这里不能用ans去找dp数组中的最小值！！！
        //注意本题问的是什么！以及dp数组的含义！
        //本题问的是使得word1和word2相同的最小步数
        //你用ans去找dp数组中的最小值是错误的，因为你找到的大概率不是使得word1和word2相同的最小步数
        //而是使得word1中的一部分单词和word2中的一部分单词相同的最小步数。#最小步数产生于没有遍历完整个字符串
        //int ans = INT_MAX;
        
        for(int i = 1; i <= word1.size(); ++i)
        {
            for(int j = 1; j <= word2.size(); ++j)
            {
                if(word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + 2});
            }
        }
        //根据dp数组的含义，我们要求的结果就是下面的这个
        return dp[word1.size()][word2.size()];
    }
};