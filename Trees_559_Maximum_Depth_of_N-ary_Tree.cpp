// Given a n-ary tree, find its maximum depth.
// The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
// Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).

class Solution {
	int maxD = 0;
public:
    int maxDepth(Node* root, int d=0) {
  		if(!root) return 0;

  		d = d+1;
  		if(maxD < d) maxD = d;
  		for(auto child: root->children){
  			maxDepth(child, d);
  		}
  		return maxD;
    }
};