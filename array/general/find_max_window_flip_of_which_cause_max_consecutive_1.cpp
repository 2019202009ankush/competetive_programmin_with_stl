/* find two point on array such that between that window fliping the bit cause maximum number of consecutive 1
   Written By:Ankush Mitra
   Date:25.12.19 Time:13.43*/
   vector<int> Solution::flip(string A) {
       // modified kaden
       int max_so_far=0;

       int left=0;
       int right=0;
       int max_possible=0;
       bool isAll1=true;
       int global_start;
       int global_end;
       for(int i=0;i<A.size();i++)
       {
           if(A[i]=='0')
           {
               // cout<<"here"<<endl;
               isAll1=false;
               max_possible++;
               right=i;
           }
           else
           {
               max_possible--;
           }
           if(max_possible<0)
           {
               max_possible=0;
               left=i+1;
               right=i+1;
           }
           if(max_so_far<max_possible)
           {
               global_start=left;
               global_end=right;
               max_so_far=max_possible;
           }
       }
       // cout<<global_start<<" "<<global_end<<endl;
       // cout<<isAll1<<endl;
       vector<int>ret;
       if(isAll1) return ret;
       else
       {

           ret.push_back(global_start+1);
           ret.push_back(global_end+1);
           return ret;
       }
   }
