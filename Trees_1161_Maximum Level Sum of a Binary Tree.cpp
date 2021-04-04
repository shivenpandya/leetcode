// 1161. Maximum Level Sum of a Binary Tree
// Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

// Return the smallest level x such that the sum of all the values of nodes at level x is maximal.

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
      if(!root) return 0;
      
      int maxLevel = 1, curLevel = 0;
      long maxSum = root->val;
      queue<TreeNode*> q;
      q.push(root);
      
      TreeNode* cur;
      while(!q.empty()){
        int size = q.size();
        long curSum = 0;
        
        curLevel++;
        for(int i=0; i<size; i++){
          cur = q.front();
          q.pop();
          
          curSum += cur->val;
          if(cur->left) q.push(cur->left);
          if(cur->right) q.push(cur->right);
        }
        if(maxSum < curSum){
          maxSum = curSum;
          maxLevel = curLevel;
        }
      }
      
      return maxLevel;
    }
};