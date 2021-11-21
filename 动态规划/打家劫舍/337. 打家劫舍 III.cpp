/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // //方法1：暴力递归   (超时)
    // int rob(TreeNode* root) 
    // {
    //     if(root == nullptr)
    //         return 0;
    //     if(root->left == nullptr && root->right == nullptr)
    //         return root->val;
        
    //     //设"当前结点"为父节点

    //     //偷父节点
    //     int val1 = root->val;
    //     //在偷了父节点后，继续递归去偷以曾孩子为根节点的树
    //     if(root->left)
    //         val1 += rob(root->left->left) + rob(root->left->right);
    //     if(root->right)
    //         val1 += rob(root->right->right) + rob(root->right->left);
        
    //     //不偷父节点，偷父节点的孩子结点
    //     int val2 = rob(root->left) + rob(root->right);
    //     return max(val1, val2);
    // }

    // //方法2. 记忆化递归
    // unordered_map<TreeNode*, int> um;
    // int rob(TreeNode* root)
    // {
    //     if(root == nullptr)
    //         return 0;
    //     if(root->left == nullptr && root->right == nullptr)
    //         return root->val;
    //     if(um[root])    //如果root已经有记录了，说明该节点在之前计算曾孙子的时候已经算过了这个结点了
    //         return um[root];

    //     //设"当前结点"为父节点

    //     //偷父节点
    //     int val1 = root->val;
    //     //在偷了父节点后，继续递归去偷以曾孩子为根节点的树
    //     if(root->left)
    //         val1 += rob(root->left->left) + rob(root->left->right);
    //     if(root->right)
    //         val1 += rob(root->right->right) + rob(root->right->left);
        
    //     //不偷父节点，偷父节点的孩子结点
    //     int val2 = rob(root->left) + rob(root->right);

    //     um[root] = max(val1, val2);     //记录root结点处的最大金额
    //     return max(val1, val2);
    // }

    //方法3. 动态规划
    vector<int> _rob(TreeNode* root)
    {
        if(root == nullptr) return {0, 0};
        
        //采用后序遍历
        vector<int> left = _rob(root->left);
        vector<int> right = _rob(root->right);

        //数组下标：1表示偷，0表示不偷
        //单层遍历逻辑: 当前结点不偷的话，就可以偷左和右了
        //             当前结点偷的话，左右孩子就不能偷了(left[0] + rigt[0] + root->val)
        int val0 = max(left[0], left[1]) + max(right[0], right[1]);
        int val1 = left[0] + right[0] + root->val;
        return {val0, val1};
    }
    
    int rob(TreeNode* root) 
    {       
        vector<int> dp = _rob(root);
        return max(dp[0], dp[1]);
    }

};