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
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int>s;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode*node=q.front();
            q.pop();
            s.insert(node->val);
            if(node->left)q.push(node->left);
            if(node->right)q.push(node->right);
        }
        for(auto it=s.begin();it!=s.end();it++){
            if(s.find(k-*(it))!=s.end() && s.find(k-*(it))!=it){
                return true;
            }
        }
        return false;
    }
};