// 99. Recover Binary Search Tree
// You are given the root of a binary search tree (BST), where exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

// Follow up: A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

// space: O(N) and time: O(NlogN)
class Solution {
public:
    void recoverTree(TreeNode* root) {
      vector<int> v;
      int k=0;
      inorder(root, v, false, k);
      sort(v.begin(), v.end());
      inorder(root, v, true, k);
    }
  
    void inorder(TreeNode* root, vector<int>& v, bool flag, int& k){
      if(!root) return;
      inorder(root->left, v, flag, k);
      if(flag){
        if(root->val == v[k]) k++;
        else{
          root->val = v[k];
          k++;
        }
      }
      else{
        v.push_back(root->val);
      }
      inorder(root->right, v, flag, k);
    }
};

