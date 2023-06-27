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
    bool isValidBST(TreeNode* root) {
        bool answer = dfs(root, LONG_MIN, LONG_MAX);
        return answer;
    }
private:
    bool dfs(TreeNode* root, long leftBound, long rightBound){
        if (root==nullptr)
        {
            return true;
        }

        if (leftBound<root->val and root->val<rightBound)
        {
            return dfs(root->left, leftBound, root->val) and dfs(root->right, root->val, rightBound);
        }
        return false;
    }
};