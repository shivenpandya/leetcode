// Given the root of a binary tree, return the inorder traversal of its nodes' values.

//Recursion:
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
      vector<int> res;
      solve(root, res);
      return res;
    }
  
    void solve(TreeNode* root, vector<int>& res){
      if(!root) return;
      solve(root->left, res);
      res.push_back(root->val);
      solve(root->right, res);
    }
};


//Iterative
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
      vector<int> res;
      if(!root) return res;
      
      stack<TreeNode*> stk;
      TreeNode* cur = root;
      while(cur != NULL || !stk.empty()){
        while(cur != NULL){
          stk.push(cur);
          cur = cur->left;
        }
        cur = stk.top();
        stk.pop();
        res.push_back(cur->val);
        cur = cur->right;
      }
      return res;
    }
};