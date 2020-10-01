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
    int height(TreeNode* root) {
        if (root == NULL)return 0;
        int ls = height(root->left);
        int rs = height(root->right);
        return max(ls, rs) + 1;
    }
    int deepestLeavesSum(TreeNode* root) {
        if (root == NULL)return 0;
        int hs = height(root);
        map<TreeNode*, int>dis;
        dis[root] = 0;
        queue<TreeNode*>q;
        q.push(root);
        int sum = 0;
        while (!q.empty()) {
            TreeNode*curr = q.front();
            q.pop();
            if (curr->left == NULL and curr->right == NULL and dis[curr] == hs - 1)sum = sum + curr->val;

            if (curr->left) {
                q.push(curr->left);
                dis[curr->left] = dis[curr] + 1;
            }
            if (curr->right) {
                q.push(curr->right);
                dis[curr->right] = dis[curr] + 1;
            }



        }

        return sum;
    }
};