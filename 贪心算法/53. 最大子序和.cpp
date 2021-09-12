class Solution {
public:
    //贪心算法
    int maxSubArray(vector<int>& nums) 
    {
        int ans = nums[0], sum = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            sum += nums[i];
            //ans记录最大和
            if(sum > ans)
                ans = sum;
            
            //如果sum是负的，那么将其重置为0。也就是舍弃之前的组合之和。（因为负数 + 任何数都会变小）
            if(sum < 0)
                sum = 0;
        }
        return ans;
    }
};