/* Pascal Triangle
  Written By:Ankush Mitra
  Date:25.12.19 Time:15.03*/
  vector<vector<int> > Solution::solve(int A) {
   vector<vector<int > >  List;
   if(A==0)
     return List;

 vector<int>temp;
 temp.push_back(1);
 List.push_back(temp);
 if(A==1)
   return List;
 temp.clear();
 temp.push_back(1);
 temp.push_back(1);
 List.push_back(temp);
 if(A==2)
   return List;
//  for(int i=0;i<List.size();i++)
//  {
//      for(int j=0;j<List[i].size();j++)
//      {
//          cout<<List[i][j]<<" ";
//      }
//      cout<<endl;
//  }
 for(int i=3;i<=A;i++)
 {
     vector<int> t(i,0);
     int s;
     for( s=0;s<t.size()-1;s++)
     {
         if(s==0) t[s]=List[i-2][0];
         else
         {
            //  cout<<(i-2)<<" "<<(s-1)<<endl;
             t[s]=List[i-2][s-1]+List[i-2][s];
         }
     }
     t[s]=1;
     List.push_back(t);
 }
 return List;
}
