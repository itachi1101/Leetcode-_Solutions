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
    void store(TreeNode*root, vector<int>&s) {
        if (root == NULL)return ;
        if (root->left == NULL and root->right == NULL)s.push_back(root->val);
        store(root->left, s);
        store(root->right, s);


    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>s;
        vector<int>s1;
        store(root1, s);
        store(root2, s1);
        if (s.size() != s1.size())return false;
        for (int  i = 0; i < s.size(); i++) {
            if (s[i] != s1[i])return false;
        }
        return true;
    }
};