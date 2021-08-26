class Solution {
public:
    int sum(vector<int>& v)
    {
        int sum = 0;
        for(auto& e : v)
            sum += e;
        return sum;
    }

    void backtracking(vector<int>& candidates, int target, int startIndex)
    {
        if(sum(path) == target)
        {
            ans.push_back(path);
            return;
        }
        // else if(sum(path) > target)  //剪枝的时候已经筛过了
        // {
        //     return;
        // }

        for(int i = startIndex; 
        i < candidates.size() && sum(path) + candidates[i] <= target; ++i)  //剪枝：如果下一个要push的元素比target大，那么说明该for循环接下来要遍历的所有元素都会比target大。可以直接进行剪枝，跳过该for循环就返回到上次调用的位置
        {
            path.push_back(candidates[i]);
            backtracking(candidates, target, i);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        ans.clear();
        path.clear();
        sort(candidates.begin(), candidates.end()); //必须要有序，才能进行剪枝
        backtracking(candidates, target, 0);
        return ans;
    }

    vector<int> path;
    vector<vector<int>> ans;
};