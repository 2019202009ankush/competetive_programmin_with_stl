/* Find the max value till a point of Time if the chosen no is haved every Time
   Written By:Ankush Mitra
   Date:24.12.19  Time:20.58*/
   vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
       priority_queue<pair<int,pair<int,int> > > q;
       sort(A.begin(),A.end());
       sort(B.begin(),B.end());
       int n=A.size();
       int m=n;
       map<pair<int,int>,int> ma;
       ma[{n-1,m-1}]=1;
       q.push({A[n-1]+B[m-1],{n-1,m-1}});
       int start=1;
       vector<int> List;
       while(start<=n)
       {
           pair<int,pair<int,int> > temp=q.top();
           q.pop();
           // cout<<temp.first<<" "<<temp.second.first<<" "<<temp.second.second<< endl;
           List.push_back(temp.first);
           pair<int,int> k={temp.second.first-1,temp.second.second};
           if(ma[k]==0)
           {
               q.push({A[k.first]+B[k.second],k});
               ma[k]=1;
           }
           k={temp.second.first,temp.second.second-1};
           if(ma[k]==0)
           {
               q.push({A[k.first]+B[k.second],k});
               ma[k]=1;
           }
           start++;
       }
       return List;

   }
