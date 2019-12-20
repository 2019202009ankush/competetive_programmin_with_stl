/* Pallindrome
   Written By:Ankush Mitra
   Date:19.12.19 Time:13.42*/
   int Solution::isPalindrome(string A) {
       stack<char> s;
       transform(A.begin(),A.end(),A.begin(),::tolower);
       s.push('$');
       for(int i=0;i<A.size();i++)
       {
           if(isalpha(A[i])||isdigit(A[i]))
           {
               // cout<<"here"<<A[i]<<endl;
               s.push(A[i]);

           }
       }
       for(int i=0;i<A.size();i++)
       {
           if(s.top()==A[i])
           {
               s.pop();
           }
       }

     if(s.top()=='$')
       return 1;
     else
       return 0;

   }
