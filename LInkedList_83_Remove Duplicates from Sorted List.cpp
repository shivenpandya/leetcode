// 83. Remove Duplicates from Sorted List
// Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
      if(!head || head->next == NULL) return head;
      
      
      ListNode* cur = head, *prev = NULL;
      while(cur != NULL){
        if(prev != NULL && cur->val == prev->val){
          while(cur != NULL && prev->val == cur->val) cur = cur->next;
          prev->next = cur;
        }
        prev = cur;
        if(cur != NULL) cur = cur->next;
      }
      return head;
    }
};