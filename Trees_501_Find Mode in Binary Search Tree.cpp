// 501. Find Mode in Binary Search Tree

// Given the root of a binary search tree (BST) with duplicates, return all the mode(s) (i.e., the most frequently occurred element) in it.

// If the tree has more than one mode, return them in any order.

// Assume a BST is defined as follows:

// The left subtree of a node contains only nodes with keys less than or equal to the node's key.
// The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
// Both the left and right subtrees must also be binary search trees.

class Solution {
public:
    vector<int> findMode(TreeNode* root) {
      unordered_map<int,int> m;
      vector<int> res;
      if(!root) return res;
      int maxVal = 1;
      inorder(root, m, maxVal);
      
      for(auto it: m){
        if(maxVal == it.second) res.push_back(it.first);
      }
      return res;
    }
  
    void inorder(TreeNode* root, unordered_map<int, int>& m, int& maxVal){
      if(!root) return;
      inorder(root->left, m, maxVal);
      if(m.find(root->val) == m.end()) m[root->val] = 1;
      else m[root->val]++;
      if(maxVal < m[root->val]) maxVal = m[root->val];
      inorder(root->right, m, maxVal);
    }
};