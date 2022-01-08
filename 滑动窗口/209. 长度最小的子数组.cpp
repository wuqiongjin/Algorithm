class Solution {
public:
    //滑动窗口
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int length = INT_MAX;
        int left = 0, right = 0;//滑动窗口的左右边框
        int sum = 0;
        while(right < nums.size())
        {
            sum += nums[right];
            // 注意这里使用while，每次更新 left（起始位置），并不断比较子序列是否符合条件
            while(sum >= target)
            {
                length = min(length, right - left + 1);
                sum -= nums[left];// 这里体现出滑动窗口的精髓之处，不断变更left（子序列的起始位置）
                ++left;
            }
            ++right;
        }
        if(length == INT_MAX)
            return 0;

        return length;
    }
};



// //暴力解法 O(n^2)
// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums) 
//     {
//         int n = nums.size();
//         int sum = 0, length = 100001;
//         for(int start = 0, end = 0; start < n; ++start, end = start, sum = 0)
//         {
//             while(end < n && sum < target)
//             {
//                 sum += nums[end];
//                 ++end;
//             }

//             if(sum >= target)
//                 length = min(length, end - start);
//         }

//         if(length == 100001)
//             return 0;
//         return length;
//     }
// };