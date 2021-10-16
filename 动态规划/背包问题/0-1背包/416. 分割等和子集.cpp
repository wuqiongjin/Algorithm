class Solution {
public:
    int Sum(vector<int>& v)
    {
        int sum = 0;
        for(auto& e : v)
            sum += e;
        return sum;
    }
    bool canPartition(vector<int>& nums) 
    {
        //将本题 抽象为 0-1背包
        //本题问能否将数组分割为2个和相等的子集 ---> 求背包价值为 sum / 2 的组合是否存在
        //nums中的每个元素都是物品：数字的值代表物品的大小，数字的值也代表物品的价值！！！
        //设目标和为target，我们就是要找dp[i]的值为target的组合。(01背包是求最大价值的组合)
        
        //dp[j]表示容量为j的背包的价值，而我们要在dp[j]每次更新后对其进行判断是否等于target
        int target;
        if((target = Sum(nums)) % 2)	//总和sum为奇数，直接返回false
            return false;
        else
            target /= 2;

        //dp数组只需要开辟 target + 1大小即可。
        //因为背包的容量范围是 0 ~ target ，也就dp数组的下标范围是 0 ~ target
        vector<int> dp(target + 1, 0);  //一维dp的初始化在遍历的时候进行就行。

        for(int i = 0; i < nums.size(); ++i)
        {
            for(int j = target; j >= nums[i]; --j)
            {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);	//这里为什么要用max呢？为什么还要求最大价值呢？因为我们的背包的最大容量就是target
                if(dp[j] == target)								//所以只要判断是否能将这个背包正好填满就行，如果能填满，就意味着它达到了最大价值。所以就返回true
                    return true;
            }
        }
        return false;
    }
};