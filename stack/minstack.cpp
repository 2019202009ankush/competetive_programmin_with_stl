/* Min stack
  Written By:Ankush Mitra
 Date:30.12.19 Time:19.14*/
 stack<int>s;
 stack<int>mins;

 MinStack::MinStack() {
   while(!s.empty())
     s.pop();
  while(!mins.empty())
    mins.pop();
 }

 void MinStack::push(int x) {
     s.push(x);
     if(mins.empty())
     {
         mins.push(x);
     }
     else
     {
         if(x<=mins.top())
         {
             mins.push(x);
         }
     }
 }

 void MinStack::pop() {
     if(!s.empty())
     {
         int val;

         val=s.top();
         s.pop();
     if(val==mins.top())
       {
           mins.pop();
       }
     }

 }

 int MinStack::top() {
     if(!s.empty()) return s.top();
     else return -1;
 }

 int MinStack::getMin() {
     if(!s.empty()) return mins.top();
     else return -1;
 }
