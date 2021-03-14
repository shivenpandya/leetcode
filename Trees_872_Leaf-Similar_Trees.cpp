// Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence


class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL && root2 == NULL) return true;
        if(root1 == NULL || root2 == NULL) return false;

        vector<int> v1, v2;

        dfs(root1, v1);
        dfs(root2, v2);

        if(v1.size() == v2.size()){
        	for(int i=0; i<v1.size(); i++){
        		if(v1[i] != v2[i]) return false;
        	}
        	return true;
        }
        else{
        	return false;
        }
    }

    void dfs(TreeNode* root, vector<int>& v){
    	if(!root) return;

    	if(root->left == NULL && root->right == NULL){
    		v.push_back(root->val);
    		return;
    	}

    	dfs(root->left, v);
    	dfs(root->right, v);
    }
};