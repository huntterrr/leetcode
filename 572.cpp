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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==nullptr){
            return false;
        }

        if (isIdentical(root, subRoot))
        {
            return true;
        }

        bool left = isSubtree(root->left, subRoot);
        bool right = isSubtree(root->right, subRoot);
        if (left or right)
        {
            return true;
        }
        return false;
    }
private:
    bool isIdentical(TreeNode* t, TreeNode* s){
        if (t==nullptr and s==nullptr)
        {
            return true;
        }
        if (t==nullptr or s==nullptr)
        {
            return false;
        }

        bool left = isIdentical(t->left, s->left);
        bool right = isIdentical(t->right, s->right);
        if ((left and right) and t->val==s->val)
        {
            return true;
        }
        return false;
    }
};