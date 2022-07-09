class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        //dp[i]: 从0~i之间，以i作为递增子序列的"结尾元素"的最长子序列长度为dp[i]
        //也就是说dp[nums.size() - 1]的值并不一定是最大的那个
        vector<int> dp(nums.size(), 1);
        int ans = 1;    //存放最长的递增子序列的长度

        for(int i = 1; i < nums.size(); ++i)
        {
            for(int j = 0; j <= i - 1; ++j)
            {
                if(nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            //找出dp数组中的最大值
            if(ans < dp[i]) 
                ans = dp[i];
        }
        return ans;
    }
};


//N-2	注释很有参考意义哦!
class Solution {
public:
    //dp[i]: 从0~i之间截取序列, 并以i为递增子序列的结尾元素的最长子序列的长度为dp[i]
    //"位置i的最长升序子序列等于 j从 0 到 i-1 各个位置的最长升序子序列 + 1 的最大值。"
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int res = 1;

        for(int i = 1; i < nums.size(); ++i)
        {
            for(int j = 0; j <= i - 1; ++j)
            {
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i], dp[j] + 1);  //这里取max并不是比较的含义, 而是让dp[i]保存 j从0到i-1遍历过程中的最大值!
                }
            }
            res = max(res, dp[i]);  //dp[nums.size() - 1]的位置并不一定是最长的子序列(注意下dp数组的含义)
        }
        return res;
    }
};