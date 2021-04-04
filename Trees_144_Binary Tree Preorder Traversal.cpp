// 144. Binary Tree Preorder Traversal
// Given the root of a binary tree, return the preorder traversal of its nodes' values

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
      vector<int> res;
      if(!root) return res;
      stack<TreeNode*> stk;
      stk.push(root);
      while(!stk.empty()){
        TreeNode* cur = stk.top();
        stk.pop();
        
        if(cur->right) stk.push(cur->right);
        if(cur->left) stk.push(cur->left);
        res.push_back(cur->val);
      }
      return res;
    }
};