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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>>paths;
        vector<int>temp_path;
        store(root, sum, paths, temp_path);
        return paths;
    }
    void store(TreeNode*root, int sum , vector<vector<int>>&paths, vector<int>&temp_path) {
        if (root == NULL)return ;
        temp_path.push_back(root->val);
        if (root->left == nullptr and root->right == nullptr and sum == root->val) {
            paths.push_back(temp_path);
        }
        store(root->left, sum - root->val, paths, temp_path);
        store(root->right, sum - root->val, paths , temp_path);
        temp_path.pop_back();
    }
};