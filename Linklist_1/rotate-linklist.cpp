/* Rotate LinkList
  Wriiten By:Ankush Mitra
 Date:27.12.19 Time:23.09*/
 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) {
    if(!A||!A->next) return A;
    int len=0;
  ListNode * temp=A;
  while(temp)
  {
      len++;
      temp=temp->next;
  }
//   cout<<len<<endl;
  B=B%len;
  int beg=len-B+1;
//   cout<<beg<<endl;
  if(beg==0) return A;
  else
  {
      int count=0;
      temp=A;
      ListNode * prev=NULL;
      while(temp)
      {
          count++;
          if(count==beg) break;
          prev=temp;
      temp=temp->next;
      }
    //   cout<<prev->val<<temp->val<<endl;
      if(prev==NULL)
      {
          ListNode* h=A;
          while(h->next)
          {
              h=h->next;
          }
          h->next=A;
          ListNode * t=A->next;
          A->next=NULL;
          return t;

      }
      else
      {
          ListNode* h=A;
          while(h->next)
          {
              h=h->next;
          }
        //   cout<<h->val<<" "<<prev->val;
          h->next=A;
          ListNode * t=prev->next;
          prev->next=NULL;
          return t;
      }

  }
}
