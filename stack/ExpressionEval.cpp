/* Expression Evaluation
  Written By;Ankush mitra
  Date:30.12.19 Time:15:33*/
  int Solution::evalRPN(vector<string> &A) {
    stack<int> s;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]=="+")
        {
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            s.push(a+b);
        }
        else if(A[i]=="-")
        {
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            s.push(b-a);
        }
        else if(A[i]=="*")
        {
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            s.push(a*b);
        }
        else if(A[i]=="/")
        {
            int a=s.top();
            s.pop();
             int b=s.top();
             s.pop();
             s.push(b/a);
        }
        else
        {
          //   cout<<A[i]<<" "<<endl;
            s.push(stoi(A[i]));
        }
    }
    return s.top();
  }
