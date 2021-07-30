class Solution {
public:
    void backtracking(int n, int k ,int startIndex)
    {
        //递归终止的条件，path的大小 == k
        if(path.size() == k)    //单次纵向遍历的结束
        {
            res.push_back(path);
            return;
        }

        //横向遍历
        for(int i = startIndex; i <= n; ++i)
        {
            path.push_back(i);          //将i放入path结果中
            backtracking(n, k, i + 1);  //递归。[这题是要求组合，因此集合中的元素不能重复使用，下一次就要传 i + 1]
            path.pop_back();            //回溯，撤回处理过的结果
        }
    }

    vector<vector<int>> combine(int n, int k) 
    {
        backtracking(n, k, 1);
        return res;
    }

    vector<int> path;           //存放单次结果的路径
    vector<vector<int>> res;  //存放结果路径的集合
};