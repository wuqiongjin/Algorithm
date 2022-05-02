class Solution {
public:
    //贪心算法
    //计算覆盖的范围是否能大于等于最后一个下标的值
    //i作为下标变量进行移动
    //i只能在cover范围内移动，而每次移动时,i都可能会对cover范围进行一定的扩充(可能)
    //cover的值 = max(i移动后更新的范围, cover)
    //最终需要判断cover范围是否能够大于等于最后一个下标
    bool canJump(vector<int>& nums) 
    {
        if(nums.size() == 1) return true;
        int last = nums.size() - 1;
        int i = 0;
        int coverRange = nums[0];
        while(i <= coverRange)
        {
            if(coverRange >= last)
                return true;
            coverRange = max(i + nums[i], coverRange);
            ++i;
        }
        return false;
    }
};