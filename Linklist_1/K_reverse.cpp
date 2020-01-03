/*  K reverse of link List
   Written By:ankush Mitra
   Date:2.1.20 Time:23.51 */
   ListNode* Solution::reverseList(ListNode* A, int B) {
       ListNode * c=A;
       ListNode* prev=NULL;
       ListNode* n;
       int count=0;
       while(count<B&&c)
       {
           n=c->next;
           c->next=prev;
           prev=c;
           c=n;
       }
       if(n)
       {
           A->next=reverseList(n,B);
       }
       return prev;

   }
