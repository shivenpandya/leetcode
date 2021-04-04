// 116. Populating Next Right Pointers in Each Node
// You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

// struct Node {
//   int val;
//   Node *left;
//   Node *right;
//   Node *next;
// }
// Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

// Initially, all next pointers are set to NULL.

//Iterative
class Solution {
public:
    Node* connect(Node* root) {
      if(!root) return NULL;
      
      queue<Node*> q;
      q.push(root);
      while(!q.empty()){
        int size = q.size();
        Node* cur;
        for(int i=0; i<size; i++){
          cur = q.front();
          q.pop();
          if(cur->left) q.push(cur->left);
          if(cur->right) q.push(cur->right);
          if(i < size-1) cur->next = q.front();
        }
      }
      return root;
    }
};