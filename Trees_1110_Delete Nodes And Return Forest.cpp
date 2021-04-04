// 1110. Delete Nodes And Return Forest
// Given the root of a binary tree, each node in the tree has a distinct value.

// After deleting all nodes with a value in to_delete, we are left with a forest (a disjoint union of trees).

// Return the roots of the trees in the remaining forest. You may return the result in any order.


class Solution {
public:
    bool check(vector<int>v, int val){
      for(auto x: v){
        if(x == val) return true;
      }
      return false;
    }
  
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
      vector<TreeNode*> res;
      if(!root) return res;
      TreeNode* newRoot = postOrder(root, to_delete, res);
      if(newRoot && newRoot->val == root->val) res.push_back(newRoot);
      return res;
    }
  
    TreeNode* postOrder(TreeNode* root, vector<int> to_delete, vector<TreeNode*>& res){
      if(!root) return root;
      root->left = postOrder(root->left, to_delete, res);
      root->right = postOrder(root->right, to_delete, res);
      if(check(to_delete, root->val)){
        if(root->left) res.push_back(root->left);
        if(root->right) res.push_back(root->right);
        root = NULL;
      }
      return root;
    }
};