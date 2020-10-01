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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>v;
        queue<TreeNode*>q;
        queue<TreeNode*>s;
        q.push(root1);
        s.push(root2);
        while (!q.empty()) {
            TreeNode*curr = q.front();
            q.pop();
            if (curr != NULL)
            {   v.push_back(curr->val);
                if (curr->left)q.push(curr->left);
                if (curr->right)q.push(curr->right);
            }
        }
        while (!s.empty()) {
            TreeNode*curr = s.front();
            s.pop();
            if (curr != NULL)
            {   v.push_back(curr->val);
                if (curr->left)s.push(curr->left);
                if (curr->right)s.push(curr->right);
            }
        }

        sort(v.begin(), v.end());
        return v;
    }
};