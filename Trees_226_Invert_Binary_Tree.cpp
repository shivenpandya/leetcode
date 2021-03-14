// Given the root of a binary tree, invert the tree, and return its root.

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;

        queue<TreeNode*> q;
        q.push(root);

        TreeNode* cur;
        while(!q.empty()){
        	cur = q.front();
        	q.pop();

        	TreeNode* curLeft = cur->left;
        	cur->left = cur->right;
        	cur->right = curLeft;
        	if(cur->left)
        		q.push(cur->left);
        	if(cur->right)
        		q.push(cur->right);
        }

        return root;
    }
};