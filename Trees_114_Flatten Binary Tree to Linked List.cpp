114. Flatten Binary Tree to Linked List

//Given the root of a binary tree, flatten the tree into a "linked list":
// The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
// The "linked list" should be in the same order as a pre-order traversal of the binary tree.

class Solution {
  TreeNode* leftEnd;
public:
    void flatten(TreeNode* root) {
      if(!root) return;
      leftEnd = NULL;
      root = postorder(root);      
    }
  
    TreeNode* postorder(TreeNode* root){
      if(!root) return NULL;
      
      root->left = postorder(root->left);
      root->right = postorder(root->right);
      if(leftEnd == NULL) 
      if(root->left){
        TreeNode* left = root->left;
        TreeNode* cur = left;
        while(cur->right != NULL) cur = cur->right;
        cur->right = root->right;
        
        root->left = NULL;
        root->right = left;
      }
      return root;
    }
};