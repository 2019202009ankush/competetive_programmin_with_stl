/* Find redudandt braces is present or not
  Written By:ankush mitra
  Date:30.12.19 Time:14.34*/
  int Solution::braces(string A) {
      stack<char> s;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]=='*'||A[i]=='+'||A[i]=='-'||A[i]=='/'||A[i]=='(')
           s.push(A[i]);
        else if(A[i]==')')
        {
            if(s.top()=='(') return 1;
            while(!s.empty()&&s.top()!='(')
               s.pop();
            if(!s.empty()) s.pop();
        }
    }
    return 0;
  }
