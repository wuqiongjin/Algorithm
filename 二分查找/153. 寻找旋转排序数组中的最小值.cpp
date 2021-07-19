// class Solution {
// public:
//     int findMin(vector<int>& nums) 
//     {
//         if(nums.size() == 1)
//             return nums[0];

//         int left = 0, right = nums.size() - 1;
//         while(left <= right)
//         {
//             int mid = ((right - left) >> 1) + left;
//             //数组是经过翻转的(翻转次数不等于 数组的长度的倍数)
//             if(nums[left] > nums[right])
//             {
//                 if(nums[mid] > nums[left])  //左区间有序，且mid在左区间中
//                 {
//                     left = mid + 1;
//                 }
//                 else if(nums[mid] < nums[left]) //右区间有序，且mid在右区间
//                 {
//                     if(nums[mid - 1] > nums[mid])   //判断当前位置是否是最小值
//                         return nums[mid];
//                     right = mid - 1;
//                 }
//                 else if(nums[mid] == nums[left])
//                     return nums[right];

//             }
//             else if(nums[left] == nums[right])  //left和right通过不断比较最后重合
//             {
//                 return nums[left];
//             }
//             else    //nums[left] < nums[right]  数组有序的
//             {
//                 return nums[left];
//             }
//         }
//         return nums[left];
//     }
// };



class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        //选用基准值进行二分查找    这里选择nums[right]
        int left = 0, right = nums.size() - 1;
        while(left < right)         //这里不能取=，当left == right时，就已经找到了目标值了
        {
            int mid = ((right - left) >> 1) + left;
            
            if(nums[mid] < nums[right])       //[mid + 1, right] 的值都可以舍弃,因为都比mid大
            {
                right = mid;
            }
            else //nums[mid] > nums[right]    //[left, mid] 的值都可以舍弃，因为都比 right的值大
            {
                left = mid + 1;
            }
        }
        return nums[right];
    }
};