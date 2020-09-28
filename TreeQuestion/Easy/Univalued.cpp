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
    void store(TreeNode*root, set<int>&s) {
        if (root == NULL)return ;
        s.insert(root->val);
        store(root->left, s);
        store(root->right, s);
        return ;
    }
    bool isUnivalTree(TreeNode* root) {
        set<int>s;
        store(root, s);
        if (s.size() == 1)return true;
        else return false;
    }
};