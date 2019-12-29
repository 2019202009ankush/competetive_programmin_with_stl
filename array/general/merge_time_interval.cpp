/*merge Interval of time
Written By:Ankush Mitra
Date:29.12.19 Time:20.06*/
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool cmp(Interval I,Interval J)
{
    return I.start<=J.start;
}
vector<Interval> Solution::insert(vector<Interval> &A, Interval newInterval) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
   A.push_back(newInterval);
   sort(A.begin(),A.end(),cmp);
   vector<Interval> E;
   int k;
   int j=0;
   for(int i=0;i<A.size();i++)
   {
       int mx=A[i].end;
       int mn=A[i].start;
       k=i+1;
       for(;k<A.size();k++)
       {
           if(A[k].start<=mx)
           {
               mx=max(mx,A[k].end);
               mn=min(mn,A[k].start);
           }
           else
           {
               k--;
               break;
           }
       }
       i=k;
       A[j].start=mn;
       A[j].end=mx;
       j++;
   }
   A.erase(A.begin()+j,A.end());
   return A;

}
