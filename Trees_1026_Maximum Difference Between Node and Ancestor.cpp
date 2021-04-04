// 1026. Maximum Difference Between Node and Ancestor

// Given the root of a binary tree, find the maximum value V for which there exist different nodes A and B where V = |A.val - B.val| and A is an ancestor of B.

// A node A is an ancestor of B if either: any child of A is equal to B, or any child of A is an ancestor of B.

class Solution {
  int res;
public:
    int maxAncestorDiff(TreeNode* root) {
      res = 0;
      if(!root) return res;
      
      int minVal = root->val;
      int maxVal = root->val;
      dfs(root, minVal, maxVal);
      return res;
    }
  
    void dfs(TreeNode* root, int minVal, int maxVal){
      if(!root) return;
      if(minVal > root->val) minVal = root->val;
      else if(maxVal < root->val) maxVal = root->val;
      int diff = maxVal - minVal;
      if(res < diff) res = diff;
      dfs(root->left, minVal, maxVal);
      dfs(root->right, minVal, maxVal);
    }
};