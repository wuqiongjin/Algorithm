class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        vector<int> dp(cost.size());
        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i = 2; i < cost.size(); ++i)
        {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
            //cout << dp[i] << " ";
        }

        //最后一步就是直接到头了，就相当于不用再花费了。
        //所以取倒数1和倒数2    
        return min(dp[cost.size() - 1], dp[cost.size() - 2]);
    }
};