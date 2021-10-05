class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        //只要 行或列 有一个是1，那么就只有1条路径
        if(m == 1 || n == 1)
            return 1;
        //为二维数组开辟空间
        vector<vector<int>> dp(m, vector<int>(n));  //这个构造方法好！！！，第二个位置直接传个匿名对象
        // vector<vector<int>> dp(m);
        // for(int i = 0; i < m; ++i)
        //     dp[i].resize(n);
        


        //初始化dp数组,最上一行和最左一行的所有元素都是1，因为只有1种路径
        // dp[0][0] = 1;
        for(int i = 0; i < n; ++i)
            dp[0][i] = 1;
        for(int i = 0; i < m; ++i)
            dp[i][0] = 1;

        //从(1, 1)开始遍历
        for(int i = 1; i < m; ++i)
        {
            for(int j = 1; j < n; ++j)
            {
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                // cout << dp[i][j] << " ";
            }
            // cout << endl;
        }
        return dp[m - 1][n - 1];
    }
};