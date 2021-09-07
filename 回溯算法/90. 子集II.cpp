class Solution {
public:
    void backtracking(vector<int>& nums, int startIndex, vector<bool>& used)
    {
        //由于要遍历所有节点，所以直接push_back()。去重在前面搞
        ans.push_back(path);
        if(startIndex >= nums.size())
            return;
        
        for(int i = startIndex; i < nums.size(); ++i)
        {
            if(i > 0 && nums[i - 1] == nums[i] && used[i - 1] == false) //去重
                continue;
            else
                path.push_back(nums[i]);

            used[i] = true;
            backtracking(nums, i + 1, used);
            used[i] = false;
            path.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        vector<bool> used(nums.size());
        sort(nums.begin(), nums.end());
        backtracking(nums, 0, used);
        return ans;
    }

    vector<int> path;
    vector<vector<int>> ans;
};