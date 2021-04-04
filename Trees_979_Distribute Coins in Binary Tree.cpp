// 979. Distribute Coins in Binary Tree
// You are given the root of a binary tree with n nodes where each node in the tree has node.val coins and there are n coins total.
// In one move, we may choose two adjacent nodes and move one coin from one node to another. (A move may be from parent to child, or from child to parent.)
// Return the number of moves required to make every node have exactly one coin.

class Solution {
  int ans;
public:
    int distributeCoins(TreeNode* root) {
      ans = 0;
      dfs(root);
      return ans;
    }
  
    int dfs(TreeNode* root){
      if(!root) return 0;
      int lSum = dfs(root->left);
      int rSum = dfs(root->right);
      ans += abs(lSum) + abs(rSum);
      return (root->val + lSum + rSum - 1);
   