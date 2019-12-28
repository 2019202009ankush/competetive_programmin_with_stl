/* Partition List
   Written By:ANkush Mitra
   Date:28.12.19 Time:11.42*/
   ListNode* Solution::partition(ListNode* A, int B) {
       ListNode * pt=A;
       ListNode * c=new ListNode(0);
       ListNode* start=c;
       while(pt)
       {
           if(pt->val<B)
           {
               c->next=new ListNode(pt->val);
               c=c->next;
           }
     pt=pt->next;
       }
       pt=A;
       while(pt)
       {
           if(pt->val>=B)
           {
               c->next=new ListNode(pt->val);
               c=c->next;
           }
           pt=pt->next;
       }
       return start->next;
   }
