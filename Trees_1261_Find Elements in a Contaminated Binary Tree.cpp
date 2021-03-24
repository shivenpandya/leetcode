// Given a binary tree with the following rules:

// root.val == 0
// If treeNode.val == x and treeNode.left != null, then treeNode.left.val == 2 * x + 1
// If treeNode.val == x and treeNode.right != null, then treeNode.right.val == 2 * x + 2
// Now the binary tree is contaminated, which means all treeNode.val have been changed to -1.

// You need to first recover the binary tree and then implement the FindElements class:

// FindElements(TreeNode* root) Initializes the object with a contamined binary tree, you need to recover it first.
// bool find(int target) Return if the target value exists in the recovered binary tree.
 

class FindElements {
  set<int> s;
public:
    FindElements(TreeNode* root) {
      if(root == NULL) return;
      root->val = 0;
      s.insert(root->val);
      preorder(root);
      
    }
    void preorder(TreeNode* root){
      if(root->left){
        root->left->val = root->val*2+1;
        s.insert(root->left->val);
        preorder(root->left);
      }
      if(root->right){
        root->right->val = root->val*2+2;
        s.insert(root->right->val);
        preorder(root->right);
      }
    }
  
    bool find(int target) {
      return s.count(target) ? 1: 0;
    }
};
