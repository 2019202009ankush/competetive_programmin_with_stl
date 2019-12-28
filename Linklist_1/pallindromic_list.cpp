/* Pallindrome List
   Written By:Ankush Mitra
   Date:27.12.19 Time:1.30*/
   /**
    * Definition for singly-linked list.
    * struct ListNode {
    *     int val;
    *     ListNode *next;
    *     ListNode(int x) : val(x), next(NULL) {}
    * };
    */
    ListNode * reversed ( ListNode * head)
    {
        ListNode* curr=head;
        ListNode *prev=NULL;
        ListNode *nex;
        while(curr)
        {
            nex=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nex;
        }
        return prev;
    }
    int comp(ListNode* A,ListNode *rever)
    {
        while(A&&rever)
        {
            if(A->val!=rever->val) return 0;
            A=A->next;
            rever=rever->next;
        }
        if(A||rever) return 0;
        return 1;
    }
   int Solution::lPalin(ListNode* A) {
       if(!A||!A->next) return 1;
       ListNode * fast;
       ListNode * slow;
       ListNode * prev=NULL;
       fast=A;
       slow=A;
       while(fast&&fast->next)
       {
         prev=slow;
        fast=fast->next->next;
        slow=slow->next;
       }
       if(fast)
       {
           slow=slow->next;
       }
       prev->next=NULL;
    ListNode * rever=reversed(slow);
    return comp(A,rever);
   }
