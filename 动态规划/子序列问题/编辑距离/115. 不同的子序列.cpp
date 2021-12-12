class Solution {
public:
    int numDistinct(string s, string t) 
    {
        //dp[i][j]: 所有以i-1为结尾的s序列中含有以j-1为结尾的t序列的个数为dp[i][j]
        //
        //
        vector<vector<uint64_t>> dp(s.size() + 1, vector<uint64_t>(t.size() + 1, 0));
        //初始化
        for(int i = 0; i <= s.size(); ++i)
            dp[i][0] = 1;

        for(int i = 1; i <= s.size(); ++i)
        {
            for(int j = 1; j <= t.size(); ++j)
            {
                if(s[i - 1] == t[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[s.size()][t.size()];
    }
};