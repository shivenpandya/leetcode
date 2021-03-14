// Given the root of an n-ary tree, return the preorder traversal of its nodes' values.
// Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value (See examples)

class Solution {
	vector<int> v;
public:
    vector<int> preorder(Node* root) {
    	if(!root) return v;
    	v.push_back(root->val);
        for(int i=0; i<root->children.size(); i++){
        	preorder(root->children[i]);
        }
        return v;
    }
};


//Second Method: Using Util func

class Solution {
public:
    vector<int> preorder(Node* root) {
    	vector<int> v;
    	preOrderUtil(root, v);
        return v;
    }

    void preOrderUtil(Node *root, vector<int> &v)
    {
    	if(!root) return;
    	v.push_back(root->val);

    	for(auto child:root->children){
    		preOrderUtil(child, v);
    	}
    }
};