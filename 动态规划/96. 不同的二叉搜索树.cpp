class Solution {
public:
    //见笔记
    //在整数 1 ~ n 中选取 k 作为根节点，让 1 ~ k - 1去构建左子树， k + 1 ~ n去构建右子树。
    //求在不同的 k(1 ~ n) 下，左右子树组成的BST的数量和。
    int numTrees(int n) 
    {
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2; i <= n; ++i)
        {
            for(int j = i - 1; j >= 0; --j)
            {
                //要遍历 以 1 ~ n 的所有根节点，内存循环控制下标。
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
    }
};