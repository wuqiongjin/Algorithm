class Solution {
public:
	//本题乍一看不像是dp问题
	//但是我们将其转化为dp问题
	//我们将这组数分为 left组合 和 right组合
	//那么有 left组合 - right组合 = target
	//然而我们已知 left组合 + right组合 = sum
	//推导: left - (sum - left) = target
	//		2 * left = sum + target
	//			left = (sum + target) / 2
	//所以这道题转化成了求 装满容量为left组合的背包, 有多少种装法? 
	
	//这是一道求组合方法的题
	//因此dp数组的定义如下:
	//1.dp[i][j]: 从[0,i]选取物品, 填满容量为j的背包的方法有dp[i][j]种 / dp[j]: 填满容量为j的背包有dp[j]种方法
	//2.状态转移方程: dp[j] += dp[j - nums[i]]; 填满容量为j的背包有dp[j]种方法, 那么填满容量为j-nums[i]的背包, 就有dp[j-nums[i]]种填法
	//				也就是说, dp[j] = dp[j] + dp[j - nums[i]]; 这里依然是不选取第j-nums[i]个物品和选取它 这两个状态推导出dp[j]
	//				设 j = 5
	//				如果left组合中已经包含(选取)了数字 1 (nums[i]=1)的话, 那么要凑成dp[5], 就有dp[4]种方法;
	//				如果left组合中已经包含(选取)了数字 2 (nums[i]=2)的话, 那么要凑成dp[5], 就有dp[3]种方法;
	//				如果left组合中已经包含(选取)了数字 3 (nums[i]=3)的话, 那么要凑成dp[5], 就有dp[2]种方法;
	//				如果left组合中已经包含(选取)了数字 4 (nums[i]=4)的话, 那么要凑成dp[5], 就有dp[1]种方法;
	//				如果left组合中已经包含(选取)了数字 5 (nums[i]=5)的话, 那么要凑成dp[5], 就有dp[0]种方法;
	// 那么凑成dp[5]的方法呢? 就是把所有的dp[j-nums[i]]累加起来!
	//3.dp数组的初始化:
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        int sum = 0;
        for(auto e : nums)
            sum += e;
        int left = (sum + target) / 2;

        if(abs(target) > sum)	//超出left + right的最大能组合的值, 无解
            return 0;
        if((sum + target) % 2 == 1) //根据二元一次方程组推导出来的(因为2*left一定是偶数, 所以sum + target不能为奇数)
            return 0;

        vector<int> dp(left + 1, 0);//总和为left的背包，有dp[left]种数字组合方法
        dp[0] = 1;  //总和为0的背包，有1种放法，那就是什么都不放。  
                    //※注意※:这里放入的都是正数，因为你这里的left设定的是正数的那一堆数字，并不涉及负数
        for(int i = 0; i < nums.size(); ++i)
        {
            for(int j = left; j >= nums[i]; --j)
            {
                dp[j] += dp[j - nums[i]];   //理解不了一维的话，建议转化为二维dp去找规律
            }                               //每个元素都有选/不选 2种状态!
        }
        return dp[left];
    }
};