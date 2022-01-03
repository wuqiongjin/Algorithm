//N-2
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {
        int start = 0, end = nums.size() - 1;
        vector<int> ans(nums.size(), 0);
        int index = end;
        while(start <= end)
        {
            if(abs(nums[start]) > abs(nums[end]))
            {
                ans[index--] = nums[start] * nums[start];
                ++start;
            }
            else
            {
                ans[index--] = nums[end] * nums[end];
                --end;
            }
        }
        return ans;
    }
};

//N-1
// class Solution {
// public:
//     //用双指针思路可以，比库函数sort快很多。
//     vector<int> sortedSquares(vector<int>& nums) 
//     {
//         vector<int> ans;
//         int left = 0, right = nums.size() - 1;
//         while(left <= right)
//         {
//             if(nums[left] + nums[right] >= 0)
//             {
//                 ans.push_back(nums[right] * nums[right]);
//                 --right;
//             }
//             else
//             {
//                 ans.push_back(nums[left] * nums[left]);
//                 ++left;
//             }
//         }
//         reverse(ans.begin(), ans.end());
//         return ans;
//     }
// };