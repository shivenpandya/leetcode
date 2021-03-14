// Given the root of a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only one right child.

//1st method Inorder traversal and create a new tree, which only has left node
class Solution {
	TreeNode* skewed = new TreeNode();
    TreeNode* cur = skewed;
public:
    TreeNode* increasingBST(TreeNode* root) {
  		if(root == NULL) return root;

  		increasingBST(root->left);
        cur->right = new TreeNode(root->val);
  		cur = cur->right;
  		increasingBST(root->right);
  		return skewed->right;
    }
};

//2nd Method, without using any extra space. Change the link
class Solution {
	TreeNode *cur;
public:
    TreeNode* increasingBST(TreeNode* root) {
    	TreeNode *res = new TreeNode(0);
    	cur = res;
    	inOrder(root);
    	return res->right;
    }

    void inOrder(TreeNode* root){
    	if(!root) return;

    	inOrder(root->left);
    	root->left = NULL;
    	cur->right = root;
    	cur = root;
    	inOrder(root->right);
    }
};