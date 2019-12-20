/* Find minimum fibonacci number required to make a particular sum
   Written By:Ankush Mitra
   Date:19.18.19 Time:23.36*/
   vector<int> fib(int A)
   {
       vector<int> fibo;
       fibo.push_back(1);
       fibo.push_back(1);
       int prev=1;
       int curr=1;
       while(1)
       {
           int temp=curr;
           curr=curr+prev;
           prev=temp;
           if(curr>A+1) break;
           else
           {
               fibo.push_back(curr);
           }

       }
       return fibo;


   }
   int help(vector<int>fibo,int A)
   {
       int vis[A+A];

       memset(vis,0,sizeof(vis));

       queue<int> q;
       vis[0]=1;
       q.push(0);
       int final=0;
       while(!q.empty())
       {
           final++;
           int nodeCount=q.size();
           while(nodeCount--)
           {
                        int top=q.front();

                         q.pop();
                       for(int i=0;i<fibo.size();i++)
                       {
                           int newS=top+fibo[i];
                           // cout<<newS<<" "<<final<<" "<<A<<endl;
                           if(newS==A){
                             goto l1;
                           }
                           else if(newS>A)
                            continue;
                           else
                           {
                               if(vis[newS]==0)
                               {
                                   vis[newS]=1;
                                   q.push(newS);
                               }
                           }
                       }

           }
       }
       l1:
       return final;
   }
   int Solution::fibsum(int A) {
       vector<int> fibo=fib(A);
       return help(fibo,A);
   }
