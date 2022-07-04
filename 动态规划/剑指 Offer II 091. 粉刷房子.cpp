class Solution {
public:
    //实际上, 直接使用cost数组作为dp数组也是完全可以的, 这样就省去了 创建空间和初始化的功夫了
    int minCost(vector<vector<int>>& costs) {
        vector<vector<int>> dp(costs.size(), vector<int>(3, 0));
        for(int i = 0; i < 3; ++i)
            dp[0][i] = costs[0][i];

        for(int i = 1; i < costs.size(); ++i)
        {
            for(int j = 0; j < 3; ++j)
            {
                dp[i][j] = min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]) + costs[i][j];
            }
        }

        return min({dp[costs.size() - 1][0], dp[costs.size() - 1][1], dp[costs.size() - 1][2]});
    }
};