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
	vector<int> largestValues(TreeNode* root) {
		if (root == nullptr) return {};
		queue<TreeNode*> q;
		queue<int> level;

		q.push(root);
		level.push(0);
		vector<int> mac;

		int m = -1;
		while (q.size()) {
			TreeNode *r = q.front(); q.pop();
			int l = level.front(); level.pop();
			if (r->left) {
				q.push(r->left);
				level.push(l + 1);
			}

			if (r->right) {
				q.push(r->right);
				level.push(l + 1);
			}

			if (l > m) {
				m = l;
				mac.push_back(r->val);
			} else {
				mac[l] = std::max(mac[l], r->val);
			}
		}

		return mac;
	}
};