/* Find left and right min j A[j] > A[i]
  Written By:Ankush Mitra
  date:28.12.19 Time:19.58*/
  int Solution::maxSpecialProduct(vector<int> &A) {
   int n=A.size();
   vector<int>LeftSpecialValue(n,0);
   vector<int>RightSpecialValue(n,0);
   stack<int> s;
   s.push(0);
   for(int i=1;i<n;i++)
   {
       while(!s.empty())
       {
           if(A[s.top()]>A[i]) break;
           s.pop();
       }
       LeftSpecialValue[i]=s.empty()?0:s.top();
       s.push(i);
   }

   stack<int> s1;
   s1.push(n-1);
   for(int i=n-2;i>=0;i--)
   {
       while(!s1.empty()){
       if(A[s1.top()]>A[i]) break;
      s1.pop();

       }
        RightSpecialValue[i]=s1.empty()?0:s1.top();
        s1.push(i);

   }
   long long int mod=1e9+7;
  long long int mul=INT_MIN;
  for(int i=0;i<n;i++)
  {
      mul=max(mul,(LeftSpecialValue[i] *1LL* RightSpecialValue[i]) );
  }
  return mul%mod;


  }
