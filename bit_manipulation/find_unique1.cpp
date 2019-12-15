/*Find unique number in a array with each number occuring n time except 1
  Written by:Ankush Mitra
  Date:15.12.19 Time: 17.30*/
  int singleNumber(const vector<int> &A) {
   int countBit[32];
   memset(countBit,0,sizeof(countBit));
   int n=3;
   for(int j=0;j<A.size();j++)
   {
       int currValue=A[j];
       for(int i=31;i>=0;i--)
       {
           if((currValue>>i)&1) countBit[i]++;
       }
   }
   int num=0;
   for(int i=31;i>=0;i--)
   {
       countBit[i]=countBit[i]%n;

   }
   for(int i=0;i<=31;i++)
   {
       if(countBit[i]!=0)
       {
           num=num+(pow(2,i));
       }
   }
   return num;
}
