// 513. Find Bottom Left Tree Value
// Given the root of a binary tree, return the leftmost value in the last row of the tree.

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
      if(!root) return 0;
      
      queue<TreeNode*> q;
      q.push(root);
      
      int leftVal = root->val;
      
      TreeNode* cur;
      int leftFound = false;
      while(!q.empty()){
        leftFound = false;
        int size = q.size();
        for(int i=0; i<size; i++){
          cur = q.front();
          q.pop();
          if(cur->left){
            q.push(cur->left);
            if(!leftFound){
              leftVal = cur->left->val;
              leftFound = true;
            } 
          }
          
          if(cur->right){
            q.push(cur->right);
            if(!leftFound){
              leftVal = cur->right->val;
              leftFound = true;
            }
          }
        }
      }
      
      return leftVal;
    }
};