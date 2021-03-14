// A binary tree is univalued if every node in the tree has the same value.
// Return true if and only if the given tree is univalued.

class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
		if(!root) return true;
		if(root->left && root->val != root->left->val)
			return false;
		if(root->right && root->val != root->right->val)
			return false
		return isUnivalTree(root->left) && isUnivalTree(root->right);

    }
};  