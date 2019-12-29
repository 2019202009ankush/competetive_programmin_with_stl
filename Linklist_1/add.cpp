/* Add two List
   Wriiten By:ANkush mitra
   Date=28.12.19 Time==15.35*/
   /**
    * Definition for singly-linked list.
    * struct ListNode {
    *     int val;
    *     ListNode *next;
    *     ListNode(int x) : val(x), next(NULL) {}
    * };
    */
   ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {

       int t;
      int carry=0;
      ListNode* t1=A;
      ListNode* res=new ListNode(0);
      ListNode * front=res;
      ListNode* t3=B;
      while(t1&&t3)
      {
          t=(t1->val+t3->val);
          res->next=new ListNode((t+carry)%10);
          res=res->next;
          carry=(t+carry)/10;
          t1=t1->next;
          t3=t3->next;
      }
      while(t1)
      {
           t=(t1->val);
          res->next=new ListNode((t+carry)%10);
          res=res->next;
          carry=(t+carry)/10;
          t1=t1->next;
      }
      while(t3)
      {
           t=(t3->val);
          res->next=new ListNode((t+carry)%10);
          res=res->next;
          carry=(t+carry)/10;
          t3=t3->next;
      }
      if(carry)
      {
          res->next=new ListNode(carry);
          res=res->next;
      }
      return front->next;
   }
