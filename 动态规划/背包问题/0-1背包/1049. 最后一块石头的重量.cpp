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


//N-2
class Solution {
public:
    //思路:
    //求最小可能的重量, 我们可以设想这个数组排过序后, 什么情况下的组合能让重量最小?
    //我们可以把这组数只看做2个数, 即, 把他们分成两组(每组就一个石头[求和])
    //设这组数的和为sum, 那么如果一部分的和最接近sum/2, 那么另一部分的和也是最接近sum/2的, 这样的话它们互相抵消后,
    //就保证了重量最小
    //因此, 问题转化为了, 如何求最接近sum/2的和 (即如何让背包容量为sum/2的背包最满)
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for(int e : stones)
            sum += e;
        int target = sum / 2; //向下取整 (保证 target <= sum / 2 即, sum - dp[target] - dp[target] >= 0)
        vector<int> dp(target + 1, 0);
            
        for(int i = 0; i < stones.size(); ++i)
        {
            for(int j = target; j >= stones[i]; --j)
            {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        return sum - 2 * dp[target];   //求大于sum/2的那个和 - 小于sum/2的那个和
    }
};