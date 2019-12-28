/* sort LinkList
   Written by:ANkush Mitra
   Date:28.12.19 Time:15.12*/
   ListNode* merge(ListNode *a,ListNode *b)
   {
      ListNode * h;
      if(!a) return b;
      if(!b) return a;
      if(a->val<b->val)
      {
          h=a;
          a=a->next;
      }
      else
      {
          h=b;
          b=b->next;
      }
      ListNode * p=h;
      while(a&&b)
      {
          if(a->val<b->val)
          {
              p->next=a;
              a=a->next;
          }
          else
          {
              p->next=b;
              b=b->next;
          }
          p=p->next;
      }
     while(a)
     {
         p->next=a;
              a=a->next;
              p=p->next;
     }
     while(b)
     {
          p->next=b;
              b=b->next;
              p=p->next;
     }
     return h;
   }
   ListNode * merge_sort(ListNode* A)
   {
       if(!A||!A->next) return A;
       ListNode* slow=A;
       ListNode* fast=A->next;
       while(fast&&fast->next)
     {
         slow=slow->next;
         fast=fast->next->next;
     }

     ListNode * b=slow->next;
     ListNode *a=A;
     slow->next=NULL;
     a=merge_sort(a);
     b=merge_sort(b);
     return merge(a,b);
   }
   ListNode* Solution::sortList(ListNode* A) {
       return merge_sort(A);
   }
