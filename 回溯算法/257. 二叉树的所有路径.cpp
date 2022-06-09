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
    void AddToResult()
    {
        string tmp;
        for(int i = 0; i < path.size() - 1; ++i)
        {
            tmp += to_string(path[i]);
            tmp += "->";
        }
        tmp += to_string(path[path.size() - 1]);
        res.emplace_back(tmp);
    }

    void backtracking(TreeNode* root)
    {
        path.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr){
            AddToResult();
            return;
        }


        if(root->left){
            backtracking(root->left);
            path.pop_back();    //回溯
        }
        
        if(root->right){
            backtracking(root->right);
            path.pop_back();    //回溯
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) 
    {
        if(root == nullptr) return {};
        res.clear();
        backtracking(root);
        return res;
    }

    vector<string> res;
    vector<int> path;
};