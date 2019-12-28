/* Remove the duplicate element form the List
   Written By:Ankush Mitra
   Date:27.12.19 Time:1,27*/
   /**
    * Definition for singly-linked list.
    * struct ListNode {
    *     int val;
    *     ListNode *next;
    *     ListNode(int x) : val(x), next(NULL) {}
    * };
    */
   ListNode* Solution::deleteDuplicates(ListNode* A) {
       ListNode* left=A;
       ListNode* t=A->next;
       int pr=left->val;
       while(t)
       {
           if(t->val!=pr)
           {
               left=left->next;
               left->val=t->val;
              pr=left->val;
           }
           t=t->next;
       }
     left->next=NULL;
     return A;
   }
