

// Calculate the number of nodes (count) in the binary tree.
// Start recursion of the binary tree from the root node of the binary tree with index (i) being set as 0 and the number of nodes in the binary (count).
// If the current node under examination is NULL, then the tree is a complete binary tree. Return true.
// If index (i) of the current node is greater than or equal to the number of nodes in the binary tree (count) i.e. (i>= count), then the tree is not a complete binary. Return false.
// Recursively check the left and right sub-trees of the binary tree for same condition. For the left sub-tree use the index as (2*i + 1) while for the right sub-tree use the index as (2*i + 2).
class Solution {
public:

    int countNodes(TreeNode* root) {
        if (root == NULL)return 0;
        int ans = 0;
        queue<TreeNode*>q;
        q.push(root);
        while (!q.empty()) {
            TreeNode*curr = q.front();
            q.pop();
            ans += 1;

            if (curr->left)q.push(curr->left);
            if (curr->right)q.push(curr->right);
        }
        return ans;

    }
};