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
    void solve(TreeNode*root, map<TreeNode*, TreeNode*>&parent, int &sum) {
        if (root == NULL)return;


        TreeNode*curr = parent[parent[root]];
        if (curr)
        {
            if ((curr->val) % 2 == 0)
            {
                sum += root->val;
            }
        }

        parent[root->left] = root;
        parent[root->right] = root;

        if (root->left);
        solve(root->left, parent, sum);
        if (root->right);
        solve(root->right, parent, sum);








    }
    int sumEvenGrandparent(TreeNode* root) {
        if (root == NULL)return 0;
        map<TreeNode*, TreeNode*>parent;
        parent[root] = NULL;

        int sum = 0;
        solve(root, parent, sum);
        return sum;
    }
};