class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) 
    {
        vector<pair<int, int>> vp;
        for(auto& str : strs)
        {
            int cnt1 = 0, cnt0 = 0;
            for(int i = 0; i < str.size(); ++i)
                if(str[i] == '1')
                    ++cnt1;
                else if(str[i] == '0')
                    ++cnt0;
            vp.push_back(make_pair(cnt0, cnt1));    //将每个位置变成1个pair，第一个位置放0的个数，第二个放1的个数
        }
        
        //dp[i][j]: 背包大小为能存 i个0 和 j个1 的背包的最大子集长度为 dp[i][j]
        //这里的二维数组其实相当于 我们之前题里面做的 一维dp，因此我们将按照一维dp的规则去遍历
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        //先遍历物品(strs里的每个元素)
        for(int i = 0; i < vp.size(); ++i)
        {
            //再逆向遍历背包容量
            for(int j = m; j >= vp[i].first; --j)
            {
                //要再套一层，因为有m和n 2个元素，这里就相当于确定m的所有情况下的n的所有情况，所以需要双层for
                for(int k = n; k >= vp[i].second; --k)
                {
                    dp[j][k] = max(dp[j][k], dp[j - vp[i].first][k - vp[i].second] + 1);
                }
            }
        }
        return dp[m][n];
    }
};