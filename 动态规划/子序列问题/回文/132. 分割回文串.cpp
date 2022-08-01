class Solution {
public:
    int minCut(string s) {
        //isPalindromic[i][j]: 区间[i, j]子串是否为回文串
        vector<vector<bool>> isPalindromic(s.size(), vector<bool>(s.size(), false));
        for(int i = s.size() - 1; i >= 0; --i)
        {
            for(int j = i; j < s.size(); ++j)
            {
                if(s[i] == s[j]){
                    if(j - i <= 2)  isPalindromic[i][j] = true;
                    else isPalindromic[i][j] = isPalindromic[i + 1][j - 1];
                }
            }
        }
        
        //dp[i]: [0, i]区间切割, 使得每个子串都是回文串的最少切割次数为dp[i]
        //如果[0, i]区间恰好是 回文串, 那么dp[i] = 0;
        //如果[0, i]区间不是   回文串, 那么dp[i] = dp[j] + 1;   
        //                       即, dp[i]的切割次数 = dp[j] + [j + 1, i] 区间  (问题转化给了dp[j])
        //                           我们需要保证区间[j + 1, i]一定是回文串, 也就是说 j 为切割位置
        //                           因此我们需要isPalindromic数组判断 j 应该取在何处
        vector<int> dp(s.size());
        for(int i = 0; i < s.size(); ++i)   dp[i] = i;  //初始化. 每个位置最大切割的次数就是它的下标数

        for(int i = 0; i < s.size(); ++i)
        {
            if(isPalindromic[0][i]){
                dp[i] = 0;
                continue;
            }

            for(int j = 0; j < i; ++j)
            {
                if(isPalindromic[j + 1][i]){
                    dp[i] = min(dp[i], dp[j] + 1);  //这里的min(dp[i], )的dp[i]只是为了保证最小值
                }
            }
        }

        return dp[s.size() - 1];
    }
};