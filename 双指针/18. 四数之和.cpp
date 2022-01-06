class Solution {
public:
    //和三数之和思路一样 --- 双指针   时间复杂度O(N^3)
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for(int a = 0; a < nums.size(); ++a)
        {
            //去重
            if(a > 0 && nums[a] == nums[a - 1])
                continue;

            for(int b = a + 1; b < nums.size(); ++b)
            {
                //去重
                if(b > a + 1 && nums[b] == nums[b - 1])
                    continue;
                
                int left = b + 1;
                int right = nums.size() - 1;
                while(left < right)
                {
                    //防止溢出
                    if(nums[a] + nums[b] == target - nums[left] - nums[right])
                    {
                        ans.push_back({nums[a], nums[b], nums[left], nums[right]});
                        //收缩边界
                        ++left;
                        --right;
                        //去重
                        while(left < right && nums[left] == nums[left - 1]) ++left;
                        while(left < right && nums[right] == nums[right + 1]) --right;
                    }
                    else if(nums[a] + nums[b] > target - nums[left] - nums[right])
                    {
                        --right;
                    }
                    else//nums[a] + nums[b] < target - nums[c] - nums[d]
                    {
                        ++left;
                    }
                }
            }
        }
        return ans;
    }
};