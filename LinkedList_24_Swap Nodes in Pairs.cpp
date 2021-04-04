// 24. Swap Nodes in Pairs

// Given a linked list, swap every two adjacent nodes and return its head.

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
      if(!head) return head;
      
      ListNode *fp = head, *sp = head->next;
      
      ListNode* prev = NULL;
      while(fp != NULL && sp != NULL){
        fp->next = sp->next;
        sp->next = fp;
        if(!prev) {
          head = sp;
        }
        else{
          prev->next = sp;  
        }
        
        ListNode* tmp = fp;
        fp = sp;
        sp = tmp;
        
        fp = fp->next;
        sp = sp->next;
        prev = fp;        
        // cout << fp->val << " " << sp->val << " " << prev->val << endl;
        if(fp) fp = fp->next;
        else break;
        
        if(sp) sp = sp->next;
        else break;
      }
      return head;
    }
};