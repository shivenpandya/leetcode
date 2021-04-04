// 662. Maximum Width of Binary Tree

// Given a binary tree, write a function to get the maximum width of the given tree. The maximum width of a tree is the maximum width among all levels.

// The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.

// It is guaranteed that the answer will in the range of 32-bit signed integer.

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
      int maxWidth = 0;
      if(!root) return maxWidth;
      
      queue<pair<TreeNode*,size_t>> q;
      q.emplace(root,1);
      
      TreeNode* cur;
      size_t idx, size;
      
      while(!q.empty()){
        int width = q.back().second - q.front().second + 1;
        
        if(maxWidth < width) maxWidth = width;
        
        size = q.size();
        
        for(size_t i=0; i<size; i++){
          cur = q.front().first;
          idx = q.front().second;
          q.pop();
          
          if(cur->left){
            q.emplace(cur->left, idx*2);
          }
          
          if(cur->right){
            q.emplace(cur->right, idx*2+1);
          }
        }
      }
      
      return maxWidth;
    }
};