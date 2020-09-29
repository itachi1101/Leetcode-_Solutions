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
    void store(TreeNode*root, vector<string>&v, string s) {
        if (root == NULL) {return ;}
        if (root->left || root->right)
        {   s += to_string(root->val);
            s += "->";
        }
        if (root->left == NULL and root->right == NULL) {s += to_string(root->val); v.push_back(s);}
        store(root->left, v, s);
        store(root->right, v, s);

        return ;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>v;
        string s;
        store(root, v, s);
        return v;
    }
};