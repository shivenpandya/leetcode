// 21. Merge Two Sorted Lists

// Merge two sorted linked lists and return it as a sorted list. The list should be made by splicing together the nodes of the first two lists.

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      ListNode *cur1 = l1, *cur2 = l2, *prev = NULL, *nxt = NULL;
      
      while(cur1 != NULL && cur2 != NULL){
        if(cur2->val < cur1->val){
          ListNode* node = cur2;
          cur2 = cur2->next;
          
          node->next = cur1;
          if(prev) prev->next = node;
          else l1 = node;
          prev = node;
        }
        else{
          prev = cur1;
          cur1 = cur1->next;
        }
      }
      
      if(cur2 != NULL){
        if(prev) prev->next = cur2;
        else l1 = cur2;
      }
      
      return l1;
    }
};