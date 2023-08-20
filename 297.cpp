/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string data = "";
        convert(root, data);
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> vec;
        istringstream iss(data);
        string s;
        while (iss>>s)
        {
            if(s=="null"){
                vec.push_back(-1001);
            }
            else{
                vec.push_back(stoi(s));
            }
        }
        // int index = 0;
        return build(vec);
    }
private:
    void convert(TreeNode* root, string &data){
        if (root==NULL)
        {
            data+= " null";
            return;
        }
        data+=" "+to_string(root->val);
        convert(root->left, data);
        convert(root->right, data);
    }


    TreeNode* build(vector<int>& vec) {
        if (vec.empty()) {
            return nullptr;
        }

        int val = vec[0];
        TreeNode* root = new TreeNode(vec[0]);
        vec.erase(vec.begin());

        if (val == -1001) {
            return nullptr;
        }

        root->left = build(vec);
        root->right = build(vec);
        return root;
    }

};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));