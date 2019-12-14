/*Find out if there exits two index
  such that A[j]-A[i]==k
  Written By:Ankush Mitra
  Date:14.12.19 Time:17:42*/
  int diffPossible(vector<int> &A, int B) {

    int i=0;
    int j=1;
    while(i<A.size()&&j<A.size())
    {
        if(i!=j&&A[j]-A[i]==B)
        {
           return 1;
        }
        else if(A[j]-A[i]>B)
        {
            i++;
        }
        else
        {
            j++;
        }
    }
   return 0;
  }
