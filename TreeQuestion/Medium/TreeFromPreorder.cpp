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
    TreeNode*construct(TreeNode*&root, int data) {
        if (root == nullptr)return root = new TreeNode(data);

        if (root->val > data) {
            root->left = construct(root->left, data);
        } else root->right = construct(root->right, data);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {

        TreeNode*root = NULL;
        for (auto x : preorder) {
            construct(root, x);
        }
        return root;

    }
};