class Solution {
public:
    //贪心算法：只记录峰谷的2个值
    int wiggleMaxLength(vector<int>& nums) 
    {
        if(nums.size() <= 1)
            return nums.size();
        int prevDiff = 0, curDiff = 0, ans = 1;
        for(int i = 1; i < nums.size(); ++i)
        {
            curDiff = nums[i] - nums[i - 1];
            if((curDiff > 0 && prevDiff <= 0) || (curDiff < 0 && prevDiff >= 0))
            {
                ++ans;
                prevDiff = curDiff;
            }
        }
        return ans;
    }
};

class Solution {
public:
    //贪心算法：使用up与down巧妙计算峰值    [画个up和down的状态图]
    int wiggleMaxLength(vector<int>& nums) 
    {
        int up = 1;
        int down = 1;
        for(int i = 1; i < nums.size(); ++i)
        {
            if(nums[i] > nums[i - 1])
                up = down + 1;
            else if(nums[i] < nums[i - 1])
                down = up + 1;
        }
        return max(up, down);
    }
};
