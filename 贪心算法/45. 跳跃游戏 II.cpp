class Solution {
public:
    //思路: 依旧是按照 覆盖范围进行判断(不要按照"跳跃"的思路)
    //用i遍历数组，当i大于等于当前覆盖范围时，此时将curCover = nextCover, 此时更新范围，step++
    //
    int jump(vector<int>& nums) 
    {
        if(nums.size() == 1)    return 0;
        int last = nums.size() - 1;
        int step = 0;
        int curCover = 0;   //当前覆盖范围
        int nextCover = 0;  //下一个最大的覆盖范围

        for(int i = 0; i < nums.size(); ++i)
        {
            nextCover = max(nextCover, i + nums[i]);
            if(i == curCover){  //只有在i==当前覆盖范围时，才会去更新cur=next, 并算作走了一步
                step++;
                curCover = nextCover;
                if(curCover >= last){   //因为step初值为0。无论如何都会走一步(如果第一步就能走到终点)
                    return step;
                }
            }
        }
        return step;
    }
};