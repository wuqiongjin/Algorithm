//DP O(N^2)
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        //dp[j][i]: 以arr[j]、arr[i]为斐波那契序列结尾元素的最长斐波那契子序列的长度为dp[j][i]
        //设存在k使得arr[k] + arr[j] = arr[i] 且 k < j < i
        //那么dp[j][i] = dp[k][j] + 1;
        //如果不存在k, 那么dp[j][i] = 0;
        //关于本题的初始化问题!
        //我们可以都初始化为0, 但是在dp[j][i]的递推公式中, 必须取max(3, dp[k][j] + 1); 因为一旦最长斐波那契序列, 长度至少为3
        //如果初始化为2, 我们就不需要考虑max(3, ...)了
        unordered_map<int,int> valueToIndex;
        for(int i = 0; i < arr.size(); ++i)
            valueToIndex[arr[i]] = i;
    
        // vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), 2));
        vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), 0));
        int res = 0;
        for(int i = 2; i < arr.size(); ++i)
        {
            for(int j = i - 1; j > 0 && arr[j] * 2 > arr[i]; --j)
            {
                if(valueToIndex.count(arr[i] - arr[j])){
                    int k = valueToIndex[arr[i] - arr[j]];
                    dp[j][i] = max(3, dp[k][j] + 1);//(初始化为0的dp)如果存在k, 从长度 3 和 dp[k][j] + 1中取最大值
                    // dp[j][i] = dp[k][j] + 1; //配合上面初始化为2的dp
                }

                res = max(res, dp[j][i]);
            }
        }
        return res;
        // return res >= 3 ? res : 0;
    }
};



//暴力枚举 O(N^3)
class Solution {
public:
    //固定前两个元素, 找第三个元素+
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_map<int,int> valueToIndex;
        for(int i = 0; i < arr.size(); ++i)
            valueToIndex[arr[i]] = i;
        
        int res = 0;
        for(int i = 0; i < arr.size() - 2; ++i)
        {
            for(int j = i + 1; j < arr.size() - 1; ++j)
            {
                int count = 2;
                int val_i = arr[i], val_j = arr[j];
                while(valueToIndex.count(val_i + val_j))
                {
                    ++count;
                    int val_k = val_i + val_j;
                    val_i = val_j;
                    val_j = val_k;
                }
                res = max(res, count);
            }
        }
        return res >= 3 ? res : 0;
    }
};



//记忆化搜索 O(N^2)
class Solution {
public:
    //在暴力枚举的时候, 我们重复计算了一些斐波那契序列的长度
    //如1 2 3 5 8, 我们在以i=1,j=2时, 就已经计算了3 5 8的最长斐波那契子序列长度了, 因此后续可以直接使用

    int dfs(int i, int j, vector<int>& arr){
        if(memo[i][j]){
            return memo[i][j];
        }

        memo[i][j] = 2; //默认长度为2   (相当于初始化, 但也不是初始化, 不能在主函数里面resize时初始化)
        if(valueToIndex.count(arr[i] + arr[j])){
            int k = valueToIndex[arr[i] + arr[j]];
            memo[i][j] = dfs(j, k, arr) + 1;    //递归寻找一下层 (递归函数的返回值是以i和j为起始元素的最长斐波那契子序列的长度)
        }

        return memo[i][j];
    }

    int lenLongestFibSubseq(vector<int>& arr) {
        for(int i = 0; i < arr.size(); ++i)
            valueToIndex[arr[i]] = i;

        memo.resize(arr.size(), vector<int>(arr.size(), 0));    //不能这里初始化为2哦! (不然dfs直接返回了)
        int res = 0;
        for(int i = 0; i < arr.size() - 2; ++i)
        {
            for(int j = i + 1; j < arr.size() - 1; ++j)
            {
                int count = dfs(i, j, arr);
                if(count >= 3){
                    res = max(res, count);
                }
            }
        }
        return res;
    }

    unordered_map<int,int> valueToIndex;
    vector<vector<int>> memo;
};