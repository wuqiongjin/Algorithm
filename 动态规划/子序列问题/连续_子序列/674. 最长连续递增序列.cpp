class Solution {
public:
    //贪心
    int findLengthOfLCIS(vector<int>& nums) 
    {
        int curLen = 1, ansLen = 1, i  = 0;
        while(i < nums.size() - 1)
        {
            if(nums[i] < nums[i + 1])
                ++curLen;
            else
                curLen = 1;
            if(ansLen < curLen)
                ansLen = curLen;
            ++i;
        }
        return ansLen;
    }
    
    //动态规划
    int findLengthOfLCIS(vector<int>& nums) 
    {
        vector<int> dp(nums.size(), 1);
        int ans = 1;

        for(int i = 1; i < nums.size(); ++i)
        {
            if(nums[i] > nums[i - 1])
                dp[i] = dp[i - 1] + 1;

            if(ans < dp[i]) ans = dp[i];                
        }
        return ans;
    }
};