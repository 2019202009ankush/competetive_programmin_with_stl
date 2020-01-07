/* Find unique element in a window of k size
   Written By:ANkush Mitra
   Date:6.1.20 Time:21.15*/
   vector<int> Solution::dNums(vector<int> &A, int B) {
 vector<int> list;
 unordered_map<int,int>m;
 for(int i=0;i<B;i++)
 {
     m[A[i]]++;
 }
 list.push_back(m.size());
 int j=0;
 for(int i=B;i<A.size();i++)
 {
     m[A[j]]--;
     if(m[A[j]]==0)
     {
         m.erase(A[j]);
     }
     m[A[i]]++;
     j++;
     list.push_back(m.size());
 }
 return list;
}
