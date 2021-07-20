class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        int left = 0, right = nums.size() - 1;
        while(left < right)
        {
            int mid = ((right - left) >> 1) + left;
            //当左边和右边相等的时候，会妨碍我们判断最小值出现的位置
            //我们这里++left，去掉左端点。然后重新计算mid
            if(nums[left] == nums[right])
            {
                ++left;
                continue;
            }

            if(nums[mid] > nums[right])
            {
                left = mid + 1;
            }
            else//nums[mid] <= nums[right]
            {
                right = mid;
            }
        }
        return nums[left];
    }
};