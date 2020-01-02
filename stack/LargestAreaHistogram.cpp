/* Largest area histogram
   Written by:Ankush mitra
   Date:30.12.19 Time:15.59*/
   int Solution::largestRectangleArea(vector<int> &A) {
       int i=0;
       stack<int> s;
       int gm=INT_MIN;
       while(i<A.size())
       {
           if(s.empty()||A[i]>=A[s.top()])
           {
               s.push(i++);
           }
           else
           {
               int h=s.top();
               s.pop();
               int w=i;
               if(!s.empty())
               {
                   w-=(s.top()+1);
               }
               gm=max(gm,w*(A[h]));
           }
       }
     while(!s.empty())
     {
         int h=s.top();
         s.pop();
         int w=i;
         if(!s.empty())
         {
             w-=(s.top()+1);
         }
         gm=max(gm,w*(A[h]));
     }
     return gm;
   }
