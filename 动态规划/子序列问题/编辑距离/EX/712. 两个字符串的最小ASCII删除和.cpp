class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        //1. 确定dp数组的含义
        //以i - 1为结尾的字符串s1和j - 1为结尾的字符串s2 达到相同所需要删除的ASCII值的最小和为dp[i][j]
        //2. 确定状态转移方程
        //当s1[i - 1] == s2[j - 1]
        //dp[i][j] = dp[i - 1][j - 1]
        //当s1[i - 1] != s2[j - 1]
        //dp[i][j] += min({dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1], dp[i - 1][j - 1] + s1[i - 1] + s2[j - 1]});
        vector<vector<uint32_t>> dp(s1.size() + 1, vector<uint32_t>(s2.size() + 1, 0));
        //3. 初始化
        //第0行
        for(int j = 1; j <= s2.size(); ++j) dp[0][j] = dp[0][j - 1] + s2[j - 1];
        //第0列
        for(int i = 1; i <= s1.size(); ++i) dp[i][0] = dp[i - 1][0] + s1[i - 1];
    
        for(int i = 1; i <= s1.size(); ++i)
        {
            for(int j = 1; j <= s2.size(); ++j)
            {
                if(s1[i - 1] == s2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else{
                    // dp[i][j] = min({dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1], dp[i - 1][j - 1] + s1[i - 1] + s2[j - 1]});
                    dp[i][j] = min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);
                    //两个字符都删除的情况已经包含在了前面两种里面了(因为如果只删除一个字符, 还不行的话, 它会继续把另一个字符串的字符也删掉, 所以它里面已经包含了同时删除2个字符的情况了)
                }
            }
        }
        return dp[s1.size()][s2.size()];
    }
};