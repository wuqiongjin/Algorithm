class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int left = 0, right = nums.size() - 1;
        while(left <= right)
        {
            int mid = ((right - left) >> 1) + left;
            if(nums[mid] == target)
                return mid;

            //当mid落在右边的数组时
            if(nums[mid] <= nums[right])
            {
                if(nums[mid] < target && target <= nums[right])      //target也落在右边数组中
                {
                    left = mid + 1;
                }
                else //target不落在右边数组中   if(nums[mid] > target || target > nums[right]) 
                {
                    right = mid - 1;
                }
                
            }//当mid落在左边数组时
            else if(nums[mid] >= nums[left])
            {
                if(nums[mid] > target && target >= nums[left])      //target在左边数组中
                {
                    right = mid - 1;
                }
                else //target不在左边数组    if(nums[mid] < target || target < nums[left])
                {
                    left = mid + 1;
                }
            }
        }
        return -1;
    }
};