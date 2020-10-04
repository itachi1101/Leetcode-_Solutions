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
    bool isEvenOddTree(TreeNode* root) {
        // requirements: parent level .... pre_val
        // we go to the left
        /// we updates its level
        // check curr_val with pre_val
        //  for level %2 ==0
        //  the curr->val >prev->val
        // update prev->val with curr->val
        // for level%2  !=0
        //  curr->val < prev->val
        // update prev->val with curr->val
        // we go to the right and do the same
        queue<pair<int, TreeNode*>>q;
        q.push({0, root});
        int lastLevel = -1;
        int A = INT_MIN;
        int B = INT_MAX;
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            int value = curr.second->val;
            int level = curr.first;
            if (lastLevel != level) {
                A = INT_MIN;
                B = INT_MAX;
            }
            if (level % 2 == 0) {
                if (value % 2 == 1 and value > A) {
                    A = value;
                } else return false;
            }
            if (level % 2 == 1) {
                if (value % 2 == 0 and value < B) {
                    B = value;
                } else return false;
            }
            if (curr.second->left)q.push({curr.first + 1 , curr.second->left});
            if (curr.second->right)q.push({curr.first + 1, curr.second->right});
            lastLevel = level;

        }

        return true;

    }
};