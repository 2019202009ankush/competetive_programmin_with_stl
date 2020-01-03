/* Max Profit buy sell stocks atmost two
  Written By:Ankush Mitra
  Date:2.1.20 time: 18.23*/
  int Solution::maxProfit(const vector<int> &A) {
     if(A.size()<=1)
        return 0;
     if(A.size()<=3)
     {
         int mn=A[0];
         int mx=0;
         for(int i=1;i<A.size();i++)
         {
             mx=max(mx,A[i]-mn);
             mn=min(mn,A[i]);
         }
         return mx;
     }
     vector<int>right(A.size(),0);
     int mx=A[A.size()-1];
     for(int i=A.size()-2;i>=0;i--)
     {
         right[i]=max(right[i+1],mx-A[i]);
         mx=max(mx,A[i]);

     }
     int mn=A[0];
     mx=0;
     int out=0;
     for(int i=1;i<=A.size()-2;i++)
     {
         mx=max(mx,A[i]-mn);
         mn=min(mn,A[i]);
         out=max(out,right[i]+mx);
     }
     return out;

  }
