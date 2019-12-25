/* Find the missing number
   Written By:Ankush Mitra
   Date:25.12.19 Time:13.16*/
   typedef long long int ll;
   vector<int> Solution::repeatedNumber(const vector<int> &A) {
       ll sum=0;
       ll square_sum=0;
       for(int i=0;i<A.size();i++)
       {
           sum=sum+(ll)A[i];
           square_sum=(ll)square_sum+(ll)((ll)A[i]*(ll)A[i]);
       }
       int n=A.size();
       ll actual_sum=((ll)n*(ll)(n+1)/2);
       ll actual_square_sum=(ll)((ll)n*(ll)(n+1)*(ll)(2*n + 1 ))/6;
       ll sum_diff=((ll)actual_sum-(ll)sum);
       ll square_sum_diff=((ll)actual_square_sum-(ll)square_sum);
       ll x=((ll)square_sum_diff-((ll)sum_diff*(ll)sum_diff))/(2*sum_diff);//((3+x) cause x diff in sum and (3+x)^2 - 3 ^ 2 - x^ 2=2.X.3
       ll y=(ll)x+sum_diff;
     vector<int> d;
       d.push_back((int)x);
       d.push_back((int)y);
       return d;
   }
