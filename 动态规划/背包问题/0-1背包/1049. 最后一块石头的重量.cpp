class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) 
    {
        //本题核心思路：将stones"分成重量尽量相同的2堆"，这样最后互相抵消后所剩的重量是最小的
        int sum = 0;
        for(auto e : stones)
            sum += e;
        int target = (sum + 1) / 2; //向上取整
        //int target = sum / 2;     //向下取整
        //使用向下取整 (如 23/2 = 11)，return sum - 2 * dp[target]就行
        
        vector<int> dp(target + 1, 0); //dp表示容量为sum的背包 的最大重量是dp[i]
        
        for(int i = 0; i < stones.size(); ++i)
        {
            for(int j = target; j >= stones[i]; --j)
            {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }

        return abs(sum - 2 * dp[target]);
        //return sum - 2 * dp[target];  //向下取整
    }
};