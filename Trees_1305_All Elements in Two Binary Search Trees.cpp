// Given two binary search trees root1 and root2.
// Return a list containing all the integers from both trees sorted in ascending order.


class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
      vector<int> res;
      if(root1 == NULL && root2 == NULL) return res;
        
      vector<int> v1, v2;
      inorder(root1, v1);
      inorder(root2, v2);
      
      int i=0, j=0;
      while(i<v1.size() && j<v2.size()){
        if(v1[i] < v2[j]) res.push_back(v1[i++]);
        else res.push_back(v2[j++]);
      }
      
      while(i < v1.size()){
        res.push_back(v1[i++]);
      }
      
      while(j < v2.size()){
        res.push_back(v2[j++]);
      }
      
      return res;
    }
  
    void inorder(TreeNode* root, vector<int>& v){
      if(!root) return;
      inorder(root->left, v);
      v.push_back(root->val);
      inorder(root->right, v);
    }
};