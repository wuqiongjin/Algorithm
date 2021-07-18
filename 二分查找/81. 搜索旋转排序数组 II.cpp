class Solution {
public:
    bool search(vector<int>& nums, int target) 
    {
        int left = 0, right = nums.size() - 1;

        while(left <= right)
        {
            int mid = ((right - left) >> 1) + left;
            if(nums[mid] == target)
                return true;

            //本题与33题，不含重复元素的 搜索旋转排序数组 只差在这里****
            //当left和right相同的时候，我们就无法判断，mid是在左边的有序数组中，还是在右边的有序数组中
            //因此我们需要让left++直到可以判断位置。(就相当于删除掉前面的元素，因此还需要重新算mid的位置)
            //每次++left后，要重新计算出mid的值，就需要用continue跳过剩下的语句
            if(nums[left] == nums[right])
            {
                ++left;
                continue;
            }

            //mid在右区间中
            if(nums[mid] <= nums[right])
            {
                if(nums[mid] <= target && target <= nums[right])    //target在右边的有序数组中
                    left = mid + 1;
                else        //  if(nums[mid] > target || target > nums[right]) 
                    right = mid -1;

            }//mid在左区间中
            else if(nums[mid] >= nums[left])
            {
                if(nums[mid] >= target && target >= nums[left])     //target在左边的有序数组中
                    right = mid - 1;
                else        //  if(nums[mid] < target || target < nums[left])
                    left = mid + 1;
            }
        }
        return false;
    }
};