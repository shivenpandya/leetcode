// You are given the root of a binary tree where each node has a value 0 or 1.  Each root-to-leaf path represents a binary number starting with the most significant bit.  For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.
// For all leaves in the tree, consider the numbers represented by the path from the root to that leaf.
// Return the sum of these numbers. The answer is guaranteed to fit in a 32-bits integer.


// Recursive PreOrder solution
//Time: O(N), N: No. of nodes in the tree
//Space: O(H), H: height of the tree
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
    	if(!root) return 0;

        int sum = 0;
        preOrder(root, sum, 0);
        return sum;
    }

    void preOrder(TreeNode* root, int &sum, int no){
    	if(!root) return;

    	no = (no << 1) | root->val;

  		if(root->left == NULL && root->right == NULL) {
  			sum += no;
        }
  		else{
  			preOrder(root->left, sum, no);
  			preOrder(root->right, sum, no);
  		}

    }
};


// Iterative PreOrder Solution
//Time: O(N), N: No. of nodes in the tree
//Space: O(H), H: height of the tree
class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
   		if(!root) return 0;

   		stack<pair<TreeNode*, int>> s;
   		int sum = 0;
   		int no = 0;

   		s.push(make_pair(root, 0));

   		while(!s.empty()){
   			pair<TreeNode*, int> p = s.top();
            s.pop();
   			root = p.first;
   			int curNo = p.second;

   			if(root){
   				curNo = (curNo << 1) | root->val;
   				if(root->left == NULL && root->right == NULL){
   					sum += curNo;
   				}
   				else {
   					s.push(make_pair(root->left, curNo));
   					s.push(make_pair(root->right, curNo));
   				}
   			}
   		}
   		return sum;
   	}
};