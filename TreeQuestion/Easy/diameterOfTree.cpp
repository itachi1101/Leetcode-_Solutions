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
    int d = 0;
    int height (TreeNode*root) {
        if (root == nullptr)return 0;
        int ls = height(root->left);
        int rs = height(root->right);
        d = max(d, ls + rs);
        return max(ls, rs) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL)return 0;
        int k = height(root);
        return d;
    }
};