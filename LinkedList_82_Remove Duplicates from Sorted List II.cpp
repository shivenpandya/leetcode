// 82. Remove Duplicates from Sorted List II
// Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
      if(!head || head->next == NULL) return head;
      
      ListNode* cur = head, *prev = NULL;
      int val = cur->val;
      
      while(cur->next != NULL){
        if(cur->val == cur->next->val){
          val = cur->val;
          while(cur->next != NULL && val == cur->val) cur = cur->next;
          continue;
        }
        
        if(!prev) head = cur;
        else prev->next = cur;
        prev = cur;
        cur = cur->next;
      }

      if(cur->val == val) {
        if(prev) prev->next = NULL;
        else return NULL;
      }
      else{
        if(prev) prev->next= cur;
        else head = cur;
      }
      return head;
    }
};