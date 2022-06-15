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


//用了set (空间复杂度 不如 使用数组)
class Solution {
public:
    //不用再写个函数去判断了
    // bool isIncrement(){
    //     for(int i = 0; i < path.size() - 1; ++i)
    //     {
    //         if(path[i] > path[i + 1]){
    //             return false;
    //         }
    //     }
    //     return true;
    // }

    void backtracking(int startIndex, vector<int>& nums){
        if(path.size() >= 2){
            res.push_back(path);
        }
        if(startIndex >= nums.size()){
            return;
        }
        unordered_set<int> us;  //每层(这个说法不完全准确,是对于一个父亲下面的同一层)独立创建一个set(树层去重)
        for(int i = startIndex; i < nums.size(); ++i)
        {
            if((!path.empty() && nums[i] < path.back()) ||  //在这里直接用nums[i] < path.back()判断是否递增
                us.find(nums[i]) != us.end()){
                continue;        
            }
            path.push_back(nums[i]);
            us.insert(nums[i]);
            backtracking(i + 1, nums);
            path.pop_back();
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        path.clear();
        res.clear();
        backtracking(0, nums);
        return res;
    }

    vector<int> path;
    vector<vector<int>> res;
};