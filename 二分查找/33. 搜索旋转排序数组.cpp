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

//利用旋转点去进行2次二分查找
class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        //先通过一次二分查找找出旋转点，然后确定旋转点后，再在有序区间内去进行 普通的二分查找
        int left = 0, right = nums.size() - 1;
        while(left < right)
        {
            int mid = (right - left) / 2 + left + 1;
            if(nums[mid] >= nums[0])
                left = mid;
            else
                right = mid - 1;
        }

        //判断target在哪个区间
        if(target >= nums[0])
        {
            left = 0;
        }
        else
        {
            left = left + 1;
            right = nums.size() - 1;
        }

        while(left < right)
        {
            int mid = (right - left) / 2 + left;
            if(nums[mid] >= target)
                right = mid;
            else
                left = mid + 1;
        }

        //其实这里推荐用right作为结果值的，因为left可能会越界，自己试试就知道了
        //我这里就多加了个判断
        if(left >= nums.size())
            return - 1;
        return (nums[left] == target ? left : -1);
    }
};
