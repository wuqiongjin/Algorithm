class Solution {
public:
    //计算当前数组元素的总和
    int Sum(vector<int>& v)
    {
        if(v.size() == 0)
            return 0;
        int sum = 0;
        for(auto& e : v)
            sum += e;
        return sum;
    }

    void backtracking(int k, int n, int startVal)
    {
        // 剪枝操作
        if (Sum(path) > n) 
        { 
            return;
        }
        //单次纵向遍历结束
        if(path.size() == k)
        {
            //满足条件，添加到结果集合ans中
            if(Sum(path) == n)
                ans.push_back(path);
            //不满足条件直接return，继续遍历
            return;
        }

        //for循环的条件是横向遍历。 
        for(int i = startVal; i <= 9 - (k - path.size()) + 1; ++i)  //9 - (k - path.size()) + 1也是剪枝
        {
            path.push_back(i);
            backtracking(k, n, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) 
    {
        backtracking(k, n, 1);
        return ans;
    }

    vector<int> path;           //单次结果的数组
    vector<vector<int>> ans;    //结果集合
};