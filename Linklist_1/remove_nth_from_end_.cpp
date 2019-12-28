/* Remove nth element from ending
   Witten By:Ankush Mitra
   Date:27.12.19 Time:17.12*/
   /**
  * Definition for singly-linked list.
  * struct ListNode {
  *     int val;
  *     ListNode *next;
  *     ListNode(int x) : val(x), next(NULL) {}
  * };
  */
 ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
     ListNode * temp=A;
     if(!A||!A->next) return NULL;
     int len=0;
     while(temp)
     {
         len++;
         temp=temp->next;
     }
     int nth_beg=len-(B-1);
     temp=A;
     ListNode * prev=NULL;
      int count=0;

     while(temp&&count<nth_beg-1)
     {
         count++;
         prev=temp;
         temp=temp->next;
         if(count==nth_beg-1)
           break;

     }
     if(!prev) return A->next;
     prev->next=prev->next->next;
     return A;
 }
