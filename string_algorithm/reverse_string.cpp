/* Reverse the string
   Written By:Ankush Mitra
   Date:24.12.19 Time:8.51*/
   string Solution::solve(string A) {
       stringstream ss(A);
       stack<string> s;
       string temp;
       while(getline(ss,temp,' '))
       {
           s.push(temp);
       }
       string L="";
       while(!s.empty())
       {
           L+=s.top();
           s.pop();
           L+=" ";
       }
       // L[L.length()-1]='\0';
       return string(L.begin(),L.end()-1);
   }
