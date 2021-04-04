// 109. Convert Sorted List to Binary Search Tree
// Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

// For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

//Recursive
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
      vector<int> arr;
      ListNode* cur = head;
      while(cur != NULL){
        arr.push_back(cur->val);
        cur = cur->next;
      }
      int start = 0, end = arr.size()-1;
      TreeNode* res = createBST(arr, start, end);
      return res;
    }
  
    TreeNode* createBST(vector<int> arr, int start, int end){
      if(start > end) return NULL;
      
      int mid = start + (end-start)/2;
      
      TreeNode* res = new TreeNode(arr[mid]);
      res->left = createBST(arr, start, mid-1);
      res->right = createBST(arr, mid+1, end);
      return res;
      
    }
};