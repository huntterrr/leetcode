class Solution {
public:
    int goodNodes(TreeNode* root) {
        int result = 1;
        dfs(root, result, root->val);
        return result;
    }
private:
    void dfs(TreeNode* root, int &result, int maximum){
        if (root==nullptr){
            return;
        }
        int maxL = maximum;
        int maxR = maximum;
        if (root->left and root->left->val >= maximum)
        {
            result++;
            maxL = root->left->val;
        }
        if (root->right and root->right->val >= maximum)
        {
            result++;
            maxR = root->right->val;
        }
        dfs(root->left, result, maxL);
        dfs(root->right, result, maxR);
    }
};