/* Merge two sorted linklist
   Written By:Ankush Mitra
   Date:27.12.19 Time:16.51*/
   /**
  * Definition for singly-linked list.
  * struct ListNode {
  *     int val;
  *     ListNode *next;
  *     ListNode(int x) : val(x), next(NULL) {}
  * };
  */
 ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
     ListNode * start=new ListNode(0);
     ListNode * front=start;
     while(A&&B)
     {
         if(A->val<B->val)
         {
             start->next=new ListNode(A->val);
             A=A->next;
             start=start->next;
         }
         else
         {
             start->next=new ListNode(B->val);
             B=B->next;
              start=start->next;
         }
     }
     while(A)
     {
          start->next=new ListNode(A->val);
             A=A->next;
              start=start->next;
     }
     while(B)
     {
          start->next=new ListNode(B->val);
             B=B->next;
              start=start->next;
     }
     return front->next;
 }
