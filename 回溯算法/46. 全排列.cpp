class Solution {
public:
    //建议自己调试调试就明白了(没法描述)
    //主要依靠used数组, 每次都从0下标开始
    //
    //对于例子: [1,2,3]
    //添加顺序 ---> []、[1]、[1,2]、[1,2,3]  -->pop [1,2]、[1]
    //        --->     [1]、[1,3]、[1,3,2]  -->pop [1,3]、[1]、[]
    //        ---> []、[2]、[2,1]、[2,1,3]  -->pop [2,1]、[2]
    //        --->     [2]、[2,3]、[2,3,1]  -->pop [2,3]、[2]、[]
    //        ---> []、[3]、[3,1]、[3,1,2]  -->pop [3,1]、[3]
    //        --->     [3]、[3,2]、[3,2,1]  -->pop [3,2]、[3]、[]
    //  OVER
    void backtracking(vector<int>& nums, deque<bool>& used){
        if(path.size() == nums.size()){
            res.push_back(path);
            return;
        }

        //我们不需要startIndex, 因为[1,2]和[2,1]是两个集合, 我们需要的是判断一个位置的元素是否被使用
        //每次从0下标开始, 绕过那些正在被使用(true)的元素
        for(int i = 0; i < nums.size(); ++i)
        {
            if(used[i] == false){
                used[i] = true;
                path.push_back(nums[i]);
                backtracking(nums, used);
                used[i] = false;
                path.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        path.clear();
        res.clear();
        deque<bool> used(nums.size(), false);
        backtracking(nums, used);
        return res;
    }

    vector<int> path;
    vector<vector<int>> res;
};


//next_permutation库函数的使用
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end()); //必须要先排序(不然最终结果不一定全)
        
		/*res.push_back(nums);    //要自己手动添加一下第一个排序
        while(next_permutation(nums.begin(), nums.end()))	//当重新返回到第一种排序时会返回false
        {
            res.push_back(nums);
        }*/
		
		//可以使用do while循环
        do{
            res.push_back(nums);
        }while(next_permutation(nums.begin(), nums.end()));
		
        return res;
    }
};