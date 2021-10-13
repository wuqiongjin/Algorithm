//一维dp
class Solution {
public:
    /**
     * @param m: An integer m denotes the size of a backpack
     * @param A: Given n items with size A[i]
     * @param V: Given n items with value V[i]
     * @return: The maximum value
     */
    int backPackII(int m, vector<int> &A, vector<int> &V) {
        // write your code here
        int n = A.size();
        vector<int> dp(m + 1, 0);

        //滚动数组的思想在于"覆盖更新"，当你去逆序遍历该数组时，数组里面的值存储的是上一层的值。
        //因为dp[i][j]的求解需要知道dp[i - 1][j]与dp[i - 1][j - weight[i]]，
        //也就是(i, j)这个坐标的上面和左上面一侧的某个位置。
        //所以对于背包的遍历，必须要逆序遍历，因为逆序遍历不会将 左上面的位置的值 进行覆盖。
		
        //为什么一维dp必须先遍历 物品，再遍历 背包？
		//因为物品决定分层，背包决定下标的变化，我们只能按层更新！
        for(int i = 0; i < n; ++i)	//这里直接将物品0的求解放在for循环中了，不用单独拿出来也可以
        {
            for(int j = m; j >= A[i]; --j)	//这里做了优化，j >= A[i]而不是j >= 0。因为 j < A[i]的话就不用更新了dp[j]了。
            {
                if(j >= A[i])
                    dp[j] = max(dp[j], dp[j - A[i]] + V[i]);
            }
        }
        
        return dp[m];
    }
};