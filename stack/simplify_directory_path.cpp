/* Simplify Directory path
  Written By:Ankush Mitra
   Date:30.12.19 Time:12.15*/

string Solution::simplifyPath(string A) {
  if(A[A.size()-1]!='/')
    A+="/";
   stringstream ss(A);
   string t;
   vector<string> array;
   while(getline(ss,t,'/'))
   {
       array.push_back(t);
   }
   vector<string> m;
   m.push_back("/");
   for(int i=0;i<array.size();i++)
   {
       if(array[i]==".." && m.size()>1)
       {
           m.pop_back();
       }
       else if(array[i]==".." && m.size()==1) continue;
       else if(array[i]==".") continue;
       else if(array[i]!="") m.push_back("/"+array[i]);
   }
   string ans;
   if(m.size()==1) return "/";
   else
   for(auto it=m.begin()+1;it!=m.end();it++)
   {
       ans+=*it;
   }
   return ans;
}
