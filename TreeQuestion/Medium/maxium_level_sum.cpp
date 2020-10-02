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

    void solve(TreeNode*root, map<TreeNode*, int>&dist) {
        dist[root] = 1;
        queue<TreeNode*>q;
        q.push(root);
        while (!q.empty()) {
            TreeNode*curr = q.front();
            q.pop();
            if (curr->left) {
                dist[curr->left] = dist[curr] + 1;
                q.push(curr->left);
            }
            if (curr->right) {
                dist[curr->right] = dist[curr] + 1;
                q.push(curr->right);
            }
        }
    }
    int height(TreeNode*root) {
        if (root == NULL)return 0;
        int ls = height(root->left);
        int rs = height(root->right);
        return max(ls, rs) + 1;
    }
    int maxLevelSum(TreeNode* root) {

        map<TreeNode*, int>dist;
        solve(root, dist);
        int len = height(root);

        int greater = INT_MIN;
        int index = -1;
        vector<int>sum;
        sum.assign(len + 1, 0);
        for (auto child : dist) {
            sum[child.second] += child.first->val;
        }
        for (int i = 0; i < len; i++) {
            cout << sum[i] << " ";
        }
        for (int i = 1; i <= len; i++) {
            if (greater < sum[i]) {
                greater = sum[i];
                index = i;
            }
        }

        return index;
    }
};