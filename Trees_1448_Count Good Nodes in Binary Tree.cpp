// 1448. Count Good Nodes in Binary Tree
// Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.

// Return the number of good nodes in the binary tree.

class Solution {
  int res;
public:
    int goodNodes(TreeNode* root) {
      int maxVal = INT_MIN;
      res = 0;
      preOrder(root, maxVal);
      return res;
    }
  
    void preOrder(TreeNode* root, int maxVal){
      if(!root) return;
      
      if(root->val >= maxVal){
        res++;
        maxVal = root->val;
      }
      
      preOrder(root->left, maxVal);
      preOrder(root->right, maxVal);
    }
};