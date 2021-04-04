// 92. Reverse Linked List II
// Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
      if(!head || head->next == NULL || left == right) return head;

      ListNode* prev = NULL, *cur = head, *nxt = NULL;
      ListNode* start = NULL;
      
      int count = 0;
      while(cur != NULL && count < right){
        if(count + 1 == left){
          start = cur;
        }
        if(count + 1 >= left && count + 1 <= right){
          nxt = cur->next;
          cur->next = prev;
          prev = cur;
          cur = nxt;
        }
        else {
          prev = cur;
          cur = cur->next;
        }
        
        count++;
      }

      if(start == head) {
        head = prev;
        start->next = nxt;
      }
      else {
        ListNode* tmp = start->next;
        start->next = nxt;
        tmp->next = prev;
      }
      
      return head;
      
    }
};