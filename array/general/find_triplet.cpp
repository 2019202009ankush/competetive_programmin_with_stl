/* find triplet sum such that 1<a+b+c<2
   written by:Ankush Mitra
   Date:29.12.19 Time:21.50*/
   int Solution::solve(vector<string> &A) {
       double a=stod(A[0]);
       double b=stod(A[1]);
       double c=stod(A[2]);
     double sum=a+b+c;
     unordered_set<double> s;
     s.insert(a);
     s.insert(b);
     s.insert(c);
     for(int i=3;i<A.size();i++)
     {
         double num=stod(A[i]);
         double mx=INT_MIN,mn=INT_MAX;
         for(auto it=s.begin();it!=s.end();it++)
         {
             mx=max(mx,*it);
             mn=min(mn,*it);
         }
         if(sum>2)
         {
             s.erase(mx);
             sum-=mx;
             s.insert(num);
             sum+=num;
         }
         else if(sum<1)
         {
             s.erase(mn);
             sum-=mn;
             s.insert(num);
             sum+=num;
         }
         if(sum>1&&sum<2)
         return 1;

     }
     if(sum>1&&sum<2)
       return 1;
    return 0;
   }
