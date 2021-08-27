class Solution {
public:
    int Sum(vector<int>& v)
    {
        int sum = 0;
        for(auto e : v)
        {
            sum += e;
        }
        return sum;
    }

    void backtracking(vector<int>& candidates, int target, int startIndex, vector<bool>& used)
    {
        if(Sum(path) == target)
        {
            ans.push_back(path);
            return;
        }
        // else if(Sum(path) > target)  //剪枝的时候就判断过了
        //     return;

                                                        //剪枝
        for(int i = startIndex; i < candidates.size() && Sum(path) + candidates[i] <= target; ++i)
        {
            //这里进行去重
            //当该元素和上一个元素相同，且，上一个元素在这一轮还没有被用。那么就应该去除这一轮continue，因为重复了。
            if(i > 0 && (candidates[i] == candidates[i - 1]) && (used[i - 1] == false))
                continue;

            path.push_back(candidates[i]);
            used[i] = true; //用过了，改成true
            backtracking(candidates, target, i + 1, used);
            used[i] = false;//pop出来就改成false
            path.pop_back();
        } 
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        path.clear();
        ans.clear();
        vector<bool> used(candidates.size(), false);    //初始化一个根目标数组一样大小的布尔数组记录是否使用元素
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, used);
        return ans;
    }

    vector<int> path;
    vector<vector<int>> ans;
};