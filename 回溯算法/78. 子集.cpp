//思路1：

class Solution {
public:
    //建议画个图
    //我们要找的每个子集的深度，分别为1, 2, 3, ...直到nums.size()的大小。
    //因此我们可以进行size()大小次数的调用dfs
    //在每次dfs中，当path的大小与depth深度达到一致就return

    void backtracking(vector<int>& nums, int startIndex, int depth)
    {
        if(path.size() == depth)
        {
            ans.push_back(path);
            return;
        }

        for(int i = startIndex; i < nums.size(); ++i)
        {
            path.push_back(nums[i]);
            backtracking(nums, i + 1, depth);
            path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) 
    {
        path.clear();
        ans.clear();
        ans.push_back(path);

        for(int i = 1; i <= nums.size(); ++i)
        {
            backtracking(nums, 0, i);
        }
        return ans;
    }

    vector<int> path;
    vector<vector<int>> ans;
};

//思路2：

class Solution {
public:
    void backtracking(vector<int>& nums, int startIndex)
    {
        //子集，就是要遍历完整棵树。
        //路过的每个组合都要添加
        //终止条件为不能再添加，即startIndex的下标超出nums的下标范围
        ans.push_back(path);
        if(startIndex >= nums.size())
            return;

        for(int i = startIndex; i < nums.size(); ++i)
        {
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) 
    {
        path.clear();
        ans.clear();
        backtracking(nums, 0);
        return ans;
    }

    vector<int> path;
    vector<vector<int>> ans;
};