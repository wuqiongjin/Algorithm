class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));   //给匿名对象初始化为0
        
        //dp数组的初始化，还是给最上一行和最左一列初始化。
        //一旦出现了障碍物，剩下的所有元素都填0，也就是不用继续初始化了
        for(int i = 0; i < n; ++i)
        {
            if( obstacleGrid[0][i] != 1)
                dp[0][i] = 1;
            else
                break;
        }

        for(int i = 0; i < m; ++i)
        {
            if( obstacleGrid[i][0] != 1)
                dp[i][0] = 1;
            else
                break;
        }

        for(int i = 1; i < m; ++i)
        {
            for(int j = 1; j < n; ++j)
            {
                if(obstacleGrid[i][j])  // dp[i][j] = 0;
                    continue;
                else
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};