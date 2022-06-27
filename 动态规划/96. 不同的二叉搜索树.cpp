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


//N-2
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);//1到i节点组成的二叉搜索树的个数为dp[i]
        dp[0] = 1;
        
        for(int i = 0; i <= n; ++i)
        {
            for(int j = 1; j <= i; ++j)
            {
                //j从1开始遍历, 遍历到i; 将每个以 j 为头结点的BST的个数都累加起来
                //以 j 为头结点组成BST的个数为 dp[j - 1] * dp[i - j]
                //即, 左子树有dp[j-1]种组合方式 * 右子树有dp[i-j]种组合方式, 它们相乘即是j为头结点的个数
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }

        return dp[n];
    }
};