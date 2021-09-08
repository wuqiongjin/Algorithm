class Solution {
public:
    void backtracking(vector<int>& nums, int startIndex)
    {
        array<int, 201> used = {0}; //使用数组，必须要初始化
        // int used[201];

        if(path.size() >= 2)
            ans.push_back(path);
        // if(startIndex >= nums.size())
        //     return;

        for(int i = startIndex; i < nums.size(); ++i)
        {
            if((path.size() > 0 && nums[i] < path.back())   //不满足递增
            || used[nums[i] + 100] == 1)                    //去重
                continue;
            
            used[nums[i] + 100] = 1;
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) 
    {
        backtracking(nums, 0);
        return ans;
    }

    vector<int> path;
    vector<vector<int>> ans;
};