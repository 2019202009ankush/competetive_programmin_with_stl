/* find triple closest sum
   Written By:Ankush Mitra
   Date:14.12.19 Time:14:32*/
   int threeSumClosest(vector<int> &A, int B) {
       //interesting as we have to fix one point and do binary search on other
       sort(A.begin(),A.end());//to apply two pointer
       int best_sum=INT_MAX/2;//because in line 15 it can over flow
       int sum=0;
       for(int i=0;i<A.size()-2;i++)
       {
           //A[i] fixed
           int pointer1=i+1;
           int pointer2=A.size()-1;
           // no do pointer increament and decreament
           while(pointer1<pointer2)
           {
               sum=A[i]+A[pointer1]+A[pointer2];
               if(abs(B-sum)<abs(B-best_sum))
               {
                   best_sum=sum;
               }
               if(sum>B)
               {
                   pointer2--;
               }
               else
               {
                   pointer1++;
               }
           }
       }
       return best_sum;
   }
