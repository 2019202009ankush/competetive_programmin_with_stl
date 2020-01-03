/* Reverse between m to n
  Written By:ANkush Mitra
  Date:2.1.12 Time:23.52*/
  ListNode* Solution::reverseBetween(ListNode* A, int B, int C){
    ListNode * h=new ListNode(0);
    ListNode * t=h;
    h->next=A;

    int c=1;
    while(c!=B)
    {
       h=h->next;
       c++;
    }
    ListNode * start=h;
    ListNode * end=h->next;
    ListNode * curr=h->next;
    ListNode * prev=NULL;
    ListNode * n;
    while(c!=C+1)
    {
        n=curr->next;
        curr->next=prev;
        prev=curr;
        curr=n;
        c++;
    }
    start->next=prev;
    end->next=curr;
    return t->next;

}
