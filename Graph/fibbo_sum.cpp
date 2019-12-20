/* minimum fibonacci number required to make a fibsum
   Written By:Ankush Mitra
   Date:19.12.19 Time:23.43*/
   int fibsum(int A) {
       vector<int> fib;
       fib.push_back(1);
       fib.push_back(1);
       for(int i=2;fib[i-1]<A;i++)
       {
           int data=fib[i-1]+fib[i-2];
           fib.push_back(data);
       }
       int index=fib.size()-1;
       int N=A;
       int ans=0;
       while(N>0)
       {
           while(fib[index]>N) index--;
           N-=fib[index];
           ans++;
       }
       return ans;
   }
