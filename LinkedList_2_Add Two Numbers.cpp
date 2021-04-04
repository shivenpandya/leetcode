// 2. Add Two Numbers
// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode* c1 = l1;
      ListNode* c2 = l2;
      ListNode* res = new ListNode();
      ListNode* c = res;
      int rem = 0;
      while(c1 != NULL && c2 != NULL){
        int sum = c1->val + c2->val + rem;

        if(sum > 9){
          rem = 1;
          sum -= 10;
        }
        else rem = 0;

        c->next = new ListNode(sum);
        c = c->next;
        c1 = c1->next;
        c2 = c2->next;
      }
      
      while(c1 != NULL){
        int sum = c1->val + rem;
        if(sum > 9){
          rem = 1;
          sum -= 10;
        }
        else rem = 0;
        c->next = new ListNode(sum);
        c = c->next;
        c1 = c1->next;
      }

      while(c2 != NULL){
        int sum = c2->val + rem;
        if(sum > 9){
          rem = 1;
          sum -= 10;
        }
        else rem = 0;
        c->next = new ListNode(sum);
        c = c->next;
        c2 = c2->next;
      }
      
      if(rem){
        c->next = new ListNode(rem);
      }

      return res->next;
    }
};