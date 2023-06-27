class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        if(root==nullptr){
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty())
        {
            res.push_back(q.back()->val);
            int count = q.size();
            for (int i = 0; i < count; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if (node->left!=nullptr)
                {
                    q.push(node->left);
                }
                if (node->right!=nullptr)
                {
                    q.push(node->right);
                }
            }
        }
        return res;
    }
};