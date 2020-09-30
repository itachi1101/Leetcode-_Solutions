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
  bool hasPathSum(TreeNode* root, int sum) {
    if (root == NULL)return false;
    stack<TreeNode*>s;
    s.push(root);
    stack<int>q;
    q.push(sum - root->val);
    while (!s.empty()) {
      TreeNode*current_node = s.top();
      s.pop();
      int curr_sum = q.top();
      q.pop();
      if (current_node->left == NULL and current_node->right == NULL and curr_sum == 0)return true;
      if (current_node->left) {
        s.push(current_node->left);
        q.push(curr_sum - current_node->left->val);
      }
      if (current_node->right) {
        s.push(current_node->right);
        q.push(curr_sum - current_node->right->val);
      }
    }
    return false;

  }
};