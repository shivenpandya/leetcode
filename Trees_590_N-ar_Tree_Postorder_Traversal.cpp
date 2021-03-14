// Given the root of an n-ary tree, return the postorder traversal of its nodes' values.
// Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value (See examples)

//using dummy node, which points to root, this is to cover the case where root also get included in result array
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        Node* dummy = new Node(0);
        dummy->children.push_back(root);
        postOrderUtil(dummy, res);
        return res;
    }

    void postOrderUtil(Node* root, vector<int>& res){
    	if(!root) return;

    	for(auto child: root->children){
    		postOrderUtil(child, res);
    		if(child) res.push_back(child->val);
    	}
    }
};