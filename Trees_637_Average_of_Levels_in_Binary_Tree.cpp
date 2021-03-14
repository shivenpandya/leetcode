// Given the root of a binary tree, return the average value of the nodes on each level in the form of an array. Answers within 10-5 of the actual answer will be accepted.
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
    	vector<double> res;

  		if(!root) return res;

  		queue<TreeNode*> q;
  		q.push(root);
  		q.push(NULL);

  		TreeNode* cur;
  		double sum = 0, count = 0;
  		while(!q.empty()){
  			cur = q.front();
  			q.pop();

  			if(cur == NULL){
  				if(!q.empty()){
  					q.push(NULL);
  					//Depth = Depth + 1
  				}
                res.push_back(sum/count);
                sum = 0;
                count = 0;
  			}
  			else{
				count ++;
  				sum += cur->val;

  				if(cur->left)
  					q.push(cur->left);
  				if(cur->right)
  					q.push(cur->right);
  			}
  		}
        return res;
    }
};