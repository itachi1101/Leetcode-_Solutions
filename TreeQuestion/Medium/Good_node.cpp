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

    int goodNodes(TreeNode* root) {
        if (root == NULL)return 0;
        queue<pair<TreeNode*, int>>q;
        q.push({root, root->val});
        int cnt = 0;
        while (!q.empty()) {
            auto curr = q.front();
            // cout<<curr.first->val<<" "<<curr.second<<endl;
            q.pop();
            if (curr.first->left) {
                if (curr.first->left->val >= curr.second) {
                    cnt++;
                    q.push({curr.first->left, curr.first->left->val});
                }
                else {
                    q.push({curr.first->left, curr.second});
                }
            }
            if (curr.first->right) {
                if (curr.first->right->val >= curr.second) {
                    cnt++;
                    q.push({curr.first->right, curr.first->right->val});
                }
                else {
                    q.push({curr.first->right, curr.second});
                }
            }
        }




        return cnt + 1;
    }
};