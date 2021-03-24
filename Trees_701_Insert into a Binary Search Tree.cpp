// You are given the root node of a binary search tree (BST) and a value to insert into the tree. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.
// Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.

//Recursive
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL){
          TreeNode* node = new TreeNode(val);
          root = node;
        }
        else if(val < root->val){
          root->left = insertIntoBST(root->left, val);
        }
        else{
          root->right = insertIntoBST(root->right, val);
        }
      return root;
    }
};


//Iterative
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root== NULL) return new TreeNode(val);
        TreeNode* res = root;
        
        while(true){
          if(val < root->val){
            if(root->left == NULL){
              root->left = new TreeNode(val);
              break;
            }
            else root = root->left;
          }
          else{
            if(root->right == NULL){
              root->right = new TreeNode(val);
              break;
            }
            else root = root->right;
          }
        }
      
      return res;
    }
};