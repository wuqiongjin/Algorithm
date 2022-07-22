class Solution {
public:
    int numDistinct(string s, string t) {
        //1. 确定dp数组含义
        //dp[i][j]: 以i-1为结尾的字符串s中出现以j-1为结尾的子序列t的次数为dp[i][j]
        //2. 确定状态转移方程
        //情况1 
        //当s[i - 1] == t[j - 1]时:
        //我们可以选择使用s[i - 1]进行匹配, 那么结果应该等于"s[i-2]和t[j-2]比较的结果"
        //-->(正因为它匹配上了, 所以结果应该加上的是s[i-2]和t[j-2]比较的结果), 即结果是dp[i - 1][j - 1]
        //我们也可以不使用s[i - 1]进行匹配, 那么结果应该等于"s[i - 2]和t[j - 1]进行比较的结果", 
        //-->这句话等于dp[i - 1][j]
        //情况2
        //当s[i - 1] != t[j - 1]时:
        //此时应该删除s[i - 1]这个字符, 将结果转化为s[i - 2]和t[j - 1]比较的结果
        //即: dp[i - 1][j]
        vector<vector<uint64_t>> dp(s.size() + 1, vector<uint64_t>(t.size() + 1, 0));
        //3.初始化:
        //第0行: 空串中出现以字符串j-1为结尾的子序列t的个数为0
        for(int j = 1; j <= t.size(); ++j) dp[0][j] = 0;
        //第0列: 以i-1为结尾的字符串s中出现空串的个数为1 (把所有元素删完, 只有这一种方法)
        for(int i = 0; i <= s.size(); ++i) dp[i][0] = 1;
        
        for(int i = 1; i <= s.size(); ++i)
        {
            for(int j = 1; j <= t.size(); ++j)
            {
                if(s[i - 1] == t[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
                else{
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[s.size()][t.size()];
    }
};