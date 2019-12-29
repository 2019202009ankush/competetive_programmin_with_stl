/* Reorder the list l0-->l(n-1)-->l1-->l(n-2)-->l3-->l(n-3)......
   written by:ankush mitra
   date:28.12.19 time:15.31
   */
   /**
    * Definition for singly-linked list.
    * struct ListNode {
    *     int val;
    *     ListNode *next;
    *     ListNode(int x) : val(x), next(NULL) {}
    * };
    */
   ListNode * rev(ListNode * A)
   {
       ListNode * h,*prev=NULL,*curr=A,*nex=NULL;
       while(curr)
       {
           nex=curr->next;
           curr->next=prev;
           prev=curr;
           curr=nex;
       }
       return prev;
   }
   ListNode* Solution::reorderList(ListNode* A) {
       if(!A||!A->next||!A->next->next) return A;
       ListNode * slow=A;
       ListNode * fast=A;
       while(fast&&fast->next)
       {
           slow=slow->next;
           fast=fast->next->next;
       }

       ListNode * back=slow->next;
       slow->next=NULL;
       ListNode * B=rev(back);
       ListNode * h=A;
       A=A->next;
       ListNode* p=h;
       p->next=B;
       B=B->next;
       p=p->next;
       while(A&&B)
       {
           p->next=A;
           A=A->next;
           p=p->next;
           p->next=B;
           B=B->next;
           p=p->next;
       }
      while(A)
      {
          p->next=A;
           A=A->next;
           p=p->next;
      }
      while(B)
      {
           p->next=B;
           B=B->next;
           p=p->next;
      }
      return h;
   }
