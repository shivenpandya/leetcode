//Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
//According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

class Solution {
  TreeNode* ans;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      if(!root) return root;
      ans = NULL;
      dfs(root, p, q);
      
      return ans;
      
    }
  
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q){
      if(!root) return false;
      
      int left = dfs(root->left, p, q);
      int right = dfs(root->right, p , q);
      
      int found = 0;
      if(root == p || root == q)
        found = 1;
      
      if(found + left + right >= 2){
        ans = root;
      }
      
      return (found+left+right > 0);
    }
};