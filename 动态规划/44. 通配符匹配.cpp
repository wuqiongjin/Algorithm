class Solution {
public:
    //动态规划
    //1. dp数组的含义: dp[i][j]: 表示s的前i个字符与p的前j个字符是否匹配
    //2. 状态转移方程
    //情况1: 当 s[i - 1] == p[j - 1]:
    //       dp[i][j] = dp[i - 1][j - 1]
    //情况2: 当 p[j - 1] == '?' ; 等价于情况1, 匹配任意一个字符
    //       dp[i][j] = dp[i - 1][j - 1]
    //情况3: 当 p[j - 1] == '*' ; 此时, *可以匹配0个字符, 1个字符, 多个字符
    //       dp[i][j] = dp[i][j - 1] || dp[i - 1][j - 1] || dp[i - 1][j]
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
        dp[0][0] = true;
        for(int j = 1; j <= p.size(); ++j)
        {
            if(p[j - 1] == '*'){
                dp[0][j] = dp[0][j - 1];    // * 这里直接匹配0次的情况, 因为s串为空, 所以*这里必须只能匹配0次的
            }
        }

        for(int i = 1; i <= s.size(); ++i)
        {
            for(int j = 1; j <= p.size(); ++j)
            {
                if(s[i - 1] == p[j - 1] || p[j - 1] == '?'){
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if(p[j - 1] == '*'){
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j - 1] || dp[i - 1][j];
                }
            }
        }

        return dp[s.size()][p.size()];
    }
};