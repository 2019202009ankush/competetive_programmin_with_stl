/* Smallest sequence _generated with given_ Prime_
   Written By:Ankush Mitra
   Date:19.12.19 Time:20.55*/
   vector<int> Solution::solve(int A, int B, int C, int D) {
       int maxi=999998;

       int *prime = new int[maxi+1];
       memset(prime,0,sizeof(prime));
       prime[A]=1;
       prime[B]=1;
       prime[C]=1;
       for(int i=0;i<=maxi;i++)
       {
           if(prime[i]==1)
           {
               for(int j=2*i;j<=maxi;j+=i)
               {
                   if((j%i)==0&&prime[(j/i)]==1)
                   {
                       // cout<<j<<" "<<i<<endl;
                       prime[j]=1;
                   }
               }
           }
       }
       vector<int> list;
       int count=0;
       int i=0;
       for(;;)
       {
           if(prime[i])
           {
               list.push_back(i);
               count++;
           }
           if(count==D)
             break;
           i++;

       }
       return list;
   }
