/* Find the largest that can be made from the array
   Written By:Ankush Mittra
   Date:25.12.19 Time:18.09*/
   bool com(string a,string b)
   {
       return a+b>b+a;
   }
   string Solution::largestNumber(const vector<int> &A) {

       vector<string> list;
       bool isAllzero=true;
       for(int i=0;i<A.size();i++)
       {
           if(A[i]!=0) isAllzero=false;
           list.push_back(to_string(A[i]));
       }
       sort(list.begin(),list.end(),com);
       if(isAllzero)
         return "0";
      string ll;
       for(int i=0;i<list.size();i++)
       {
           ll+=((list[i]));
       }
       return ll;
   }
