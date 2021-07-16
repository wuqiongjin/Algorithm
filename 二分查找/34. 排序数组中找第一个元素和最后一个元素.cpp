//这里找的区间是[left, right]

class Solution {
public:
    //思路：分开寻找Left左边界和Right右边界
    int Left(vector<int>& nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while(left <= right)
        {
            int mid = ((right - left) >> 1) + left;
            if(nums[mid] < target)
            {
                left = mid + 1;
            }
            else if(nums[mid] >= target)    //左边界就是满足target的第一个元素
            {
                right = mid - 1;
            }
        }
        return left;
    }

    int Right(vector<int>& nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while(left <= right)
        {
            int mid = ((right - left) >> 1) + left;
            if(nums[mid] <= target)         //右边界就是满足target的最后一个元素
            {
                left = mid + 1;
            }
            else if(nums[mid] > target)
            {
                right = mid - 1;
            }
        }
        return right;
    }

    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int left = Left(nums, target);
        int right = Right(nums, target);
        //判断下表的有效性
        if(left > right)
            return vector<int>{-1, -1};
        return vector<int>{left, right};
    }
};