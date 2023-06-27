class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder);
    }
private:
    TreeNode* build(vector<int> preorder, vector<int> inorder){
        if (inorder.empty() or preorder.empty())
        {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorder[0]);

        auto it = find(inorder.begin(), inorder.end(), preorder[0]);
        
        int index = distance(inorder.begin(), it);
        
        root->left = build({preorder.begin()+1, preorder.begin()+index+1}, {inorder.begin(), inorder.begin()+index});
        
        root->right = build({preorder.begin()+index+1, preorder.end()}, {inorder.begin()+index+1, inorder.end()});
        
        return root;
    }
};