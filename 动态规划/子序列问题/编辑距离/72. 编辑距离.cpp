class Solution {
public:
    int minDistance(string word1, string word2) 
    {
        //dp[i][j]: 以i-1为结尾的word1和j-1为结尾的word2，将word1转为word2的最少次数为dp[i][j]
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1));
        for(int i = 0; i <= word1.size(); ++i)
            dp[i][0] = i;
        for(int i = 0; i <= word2.size(); ++i)
            dp[0][i] = i;
        
        //word1[i - 1] != word2[j - 2]的3种情况
        //1. 删除word1的i-1位置字符 --> = dp[i - 1][j] + 1
        //2. 增加word1的i-1位置字符(相当于删除word2的j-1位置字符) --> = dp[i][j - 1] + 1
        //3. 替换word1的i-1位置字符(相当于word1和word这个位置的字符相等了[此时别忘了还要 + 1]) --> = dp[i - 1][j - 1] + 1
        for(int i = 1; i <= word1.size(); ++i)
        {
            for(int j = 1; j <= word2.size(); ++j)
            {
                if(word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
            }
        }
        return dp[word1.size()][word2.size()];
    }
};