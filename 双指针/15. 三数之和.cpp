class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        //本题使用双指针: i , j 为左右指针. k为固定位置，随着k从0~num.size() - 3之间变化, i与j在剩余区间中变化
        //简而言之: 固定住k的位置，转化为双指针问题
        if(nums.size() < 3) return {};	//特殊处理
        sort(nums.begin(), nums.end());	//先排序，才能方便去重
        vector<vector<int>> ans;

        for(int k = 0; k <= nums.size() - 3; ++k)
        {
            if(nums[k] > 0) break;  //最小的元素已经大于0了，肯定找不到合为0的了

            //固定位置的选取不能重复，重复就下一轮循环了
            while(k > 0 && nums[k] == nums[k - 1])
                continue;
            
            int i = k + 1, j = nums.size() - 1;
            while(i < j)
            {
                if(nums[k] + nums[i] + nums[j] == 0)
                {
                    //找到一个三元组
                    ans.push_back({nums[k], nums[i], nums[j]});
                    ++i;
                    --j;

                    //去重, 第二个数和第三个数的选取也不能重复!!!
                    //例如：[-4,1,1,1,2,3,3,3], i=0, left=1, right=5
                    while(i < j && nums[i] == nums[i - 1]) ++i;
                    while(i < j && nums[j] == nums[j + 1]) --j;
                }
                else if(nums[k] + nums[i] + nums[j] < 0)    //总和<0，左指针左移
                    ++i;
                else// nums[k] + nums[i] + nums[j] > 0  总和>0，右指针左移
                    --j;
            }
            
        }
        return ans;
    }
};