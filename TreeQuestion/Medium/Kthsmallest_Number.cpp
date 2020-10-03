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
	void store(TreeNode*root, vector<int>&v) {
		if (root == NULL)return;
		v.push_back(root->val);
		store(root->left, v);
		store(root->right, v);
		return;
	}
	int kthSmallest(TreeNode* root, int k) {
		vector<int>v;
		store(root, v);
		sort(v.begin(), v.end());
		auto it = v.begin();

		for (int i = 1; i < k; i++) {
			it++;
		}
		return *(it);

	}
};