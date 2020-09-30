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

	int height(TreeNode*root, int &d) {
		if (root == NULL)return 0;
		int ls = height(root->left, d);
		int rs = height(root->right, d);
		d = max(d, abs(ls - rs));
		return max(ls, rs) + 1;
	}
	bool isBalanced(TreeNode* root) {
		if (root == NULL)return true;
		int d = 0;

		int k = height(root, d);
		if (d > 1)return false;
		else return true;

	}
};