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


  vector<double> averageOfLevels(TreeNode* root) {
    queue<TreeNode*>q;
    q.push(root);
    map<TreeNode*, int>m;
    m[root] = 1;
    while (!q.empty()) {
      TreeNode* temp = q.front();
      q.pop();
      if (temp->left) {
        m[temp->left] = m[temp] + 1;
        q.push(temp->left);
      }
      if (temp->right) {
        m[temp->right] = m[temp] + 1;
        q.push(temp->right);
      }
    }
    vector<double>v;
    int cnt = 0;
    int i = 1;
    int length = m.size();
    double sum = 0;
    while (length > 0) {
      for (auto child : m) {
        if (child.second == i) {
          sum += child.first->val;
          cnt++;
        }
      }
      v.push_back(sum / cnt);
      i++;
      length -= cnt;
      cnt = 0;
      sum = 0;

    }


    return v;
  }
};