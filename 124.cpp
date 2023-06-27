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
    int maxPathSum(TreeNode* root) {
        int maxPath = INT_MIN;
        dfs(root, maxPath);
        return maxPath;
    }
private:
    int dfs(TreeNode* root, int &res){
        if (root==nullptr)
        {
            return 0;
        }
        
        int left = dfs(root->left, res);
        int right = dfs(root->right, res);
        res = max({res, left+right+root->val, root->val});

        return max({max(left, right) + root->val, root->val, 0});
    }
};