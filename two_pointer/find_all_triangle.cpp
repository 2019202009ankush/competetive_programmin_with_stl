/* Find all triangle given all side size
  Written By:Ankush Mitra
  Date:14.12.19 Tim:17:24*/
  int nTriang(vector<int> &A) {
    int mod=1e9+7;
   sort(A.begin(),A.end());
   int n=A.size();
   int count=0;
   for(int i=n-1;i>=2;i--)
   {
       int pointer1=0;
       int pointer2=i-1;
       while(pointer1<pointer2){
           if(A[pointer1]+A[pointer2]>A[i])
           {
              count=(count%mod +(pointer2-pointer1)%mod  +mod )%mod;
              pointer2--;

           }
           else
           {
               pointer1++;
           }
       }
   }
   return count;
  }
