 /* Find The Maximum element in the window
   Written By:Ankush Mitra
   Date:30.12.19 Time:20.02*/
   vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
     vector<int> v;
     int w=A.size();
     deque<int>d;
     if(w<B) return v;
     else
     {
         for(int i=0;i<B;i++)
         {


             while(!d.empty()&&A[i]>=A[d.back()])
               d.pop_back();

             d.push_back(i);

         }

         for(int i=B;i<w;i++)
         {
             v.push_back(A[d.front()]);
             while(!d.empty()&&A[i]>=A[d.back()])
               d.pop_back();
             while(!d.empty()&&d.front()<=i-B)
             {
                 d.pop_front();
             }
           d.push_back(i);
         }
         // cout<<d.front()<<endl;
         v.push_back(A[d.front()]);
         return v;

     }
 }
