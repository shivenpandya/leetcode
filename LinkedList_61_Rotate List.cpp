// 61. Rotate List
// Given the head of a linked list, rotate the list to the right by k places.

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
      if(!head) return head;
      
      ListNode* cur = head;
      int size = 1;
      while(cur->next != NULL){
        cur = cur->next;
        size++;
      }
      cur->next = head;
      
      k = k % size;
      size = size - k;
      
      cur = head;
      for(int i=1; i<size; i++) cur = cur->next;
      head = cur->next;
      cur->next = NULL;
      
      
      return head;
    }
};