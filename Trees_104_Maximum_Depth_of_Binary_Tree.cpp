// A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;

       	return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
    	if(!root) return 0;
    	queue<TreeNode*> q;
    	q.push(root);
    	q.push(NULL);

    	TreeNode* cur;
    	int depth = 0;

    	while(!q.empty()){
    		cur = q.front();
    		q.pop();
            
    		if(cur == NULL){
                if(!q.empty()){
    			    q.push(NULL);
    			    depth++;   
                }
    		}
    		else{
    			if(cur->left)
    				q.push(cur->left);
    			if(cur->right)
    				q.push(cur->right);
    		}
    	}
    	return depth+1;
 	}
 };