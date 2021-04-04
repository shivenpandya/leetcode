// 19. Remove Nth Node From End of List

// Given the head of a linked list, remove the nth node from the end of the list and return its head.

// Follow up: Could you do this in one pass?

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode* fp = head, *sp = head;
      int count = n;
      
      for(int i=0; i<n; i++){
        if(sp != NULL) sp = sp->next;
      }
      
      while(sp && sp->next != NULL){
        fp = fp->next;
        sp = sp->next;
      }
      
      if(fp == head && sp == NULL) head = head->next;
      else if(n == 1) fp->next = NULL;
      else fp->next = fp->next->next;
      
      return head;
    }
};