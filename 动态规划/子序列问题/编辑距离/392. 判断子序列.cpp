class Solution {
public:
    bool isSubsequence(string s, string t) 
    {
        //这里默认是s的长度 < t的长度
        //if(s.size() == 0)   return true;
        //if(s.size() > t.size()) return false;

        //我们再开辟dp数组的时候最好多开一个空间，方便进行初始化和推导
        //dp[i][j]: 所有以i-1作为结尾的串s和以j-1作为结尾的串t，它们的相同的子序列的长度为dp[i][j]
        //我们最终想要的就是"以i-1作为结尾的串s"在t中是否出现，所以出不出现就取决于dp[s.size()][t.size()]的值
        //状态转移方程: 
        //s[i - 1] == t[j - 1]  dp[i][j] = dp[i - 1][j - 1] + 1;
        //s[i - 1] != t[j - 1]  dp[i][j] = dp[i][j - 1]; 
        //当它们不相等时, j-1就应该被删除。被删除后就是s[i-1]与t[j-2]进行比较的结果了,
        //因此dp[i][j]存储的值就变成了dp[i][j-1]
        //
        //初始化:初始化只涉及dp[0][0]与dp[i][0]
        //我们给它们赋成0就行了
        //遍历顺序:
        //通过递推公式看出，我们正向遍历就行
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));

        for(int i = 1; i <= s.size(); ++i)
        {
            for(int j = 1; j <= t.size(); ++j)
            {
                if(s[i - 1] == t[j - 1]) 
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = dp[i][j - 1];

                // if(dp[i][j] == s.size())
                //     return true;
            }
        }

        if(dp[s.size()][t.size()] == s.size())  return true;
        return false;
    }
};