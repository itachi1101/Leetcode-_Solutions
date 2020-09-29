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
    void dfs(TreeNode*root, map<int, pair<int, int>>&dis, int parent, int d) {
        if (root == NULL)return ;
        dis[root->val] = {parent, d};
        dfs(root->left, dis, root->val, d = dis[root->val].second + 1);
        dfs(root->right , dis, root->val, d = dis[root->val].second + 1);

        return ;

    }
    bool isCousins(TreeNode* root, int x, int y) {
        if (root == NULL)return false;
        map<int, pair<int, int>>dis;
        dfs(root, dis, -1, 0);
        if (dis[x].second == dis[y].second and dis[x].first != dis[y].first)return true;
        return false;
    }
};