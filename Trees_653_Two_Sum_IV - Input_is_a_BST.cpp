// Given the root of a Binary Search Tree and a target number k, return true if there exist two elements in the BST such that their sum is equal to the given target.

class Solution {
	set<int> s;
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;

        if(s.count(root->val)) return true;
        else{
        	s.insert(k-root->val);
        	return (findTarget(root->left, k) || findTarget(root->right, k));
        }
    }
};