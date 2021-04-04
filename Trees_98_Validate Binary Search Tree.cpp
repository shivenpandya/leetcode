98. Validate Binary Search Tree

// Given the root of a binary tree, determine if it is a valid binary search tree (BST).
// A valid BST is defined as follows:
// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.

class Solution {
public:
    bool isValidBST(TreeNode* root, long min=INT_MIN, long max=INT_MAX) {
      if(!root) return true;
      if(root->val < min || root->val > max) return false;
      return isValidBST(root->left, min, (long)root->val-1) && isValidBST(root->right, (long)root->val+1, max);
    }
};