// 86. Partition List
// Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

// You should preserve the original relative order of the nodes in each of the two partitions.

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
      ListNode* small = new ListNode(0);
      ListNode* big = new ListNode(0);
      
      ListNode* cur = head, *sCur = small, *bCur = big;
      
      while(cur != NULL){
        if(cur->val < x){
            sCur->next = new ListNode(cur->val);
            sCur = sCur->next;
        }
        else{
            bCur->next = new ListNode(cur->val);
            bCur = bCur->next;
        }
        
        cur = cur->next;
      }
      sCur->next = big->next;
      return small->next;
    }
};