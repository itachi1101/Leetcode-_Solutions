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
	TreeNode*solve(vector<int>nums, int start , int end) {
		if (start > end)return NULL;

		int index = start;
		for (int i = start; i <= end; i++) {
			if (nums[i] > nums[index]) {index = i;}
		}
		TreeNode*root = new TreeNode(nums[index]);
		root->left = solve(nums, start, index - 1);
		root->right = solve(nums, index + 1, end);
		return root;


	}
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		int length = nums.size();
		return solve(nums, 0, length - 1);
	}
};