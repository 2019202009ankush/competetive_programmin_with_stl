/* Remove all non unique element from the linklist
   Written By:Ankush Mitra
   Date:27.12.19 TIme:16.43*/
   /**
  * Definition for singly-linked list.
  * struct ListNode {
  *     int val;
  *     ListNode *next;
  *     ListNode(int x) : val(x), next(NULL) {}
  * };
  */
 ListNode* Solution::deleteDuplicates(ListNode* A) {
     ListNode * res=new ListNode(0);
     ListNode * temp=A;
     ListNode * start=res;
     while(temp)
     {
         if(temp->next&&temp->next->val==temp->val)
         {
             int v=temp->val;
             while(temp&&temp->val==v)
             {
                 temp=temp->next;
             }
             continue;
         }
         res->next=temp;
         res=res->next;
         temp=temp->next;
         if(res)
           res->next=NULL;
     }
     return start->next;
 }
