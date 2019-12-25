/* If the string is power of two or not
   Written By:ANkush Mitra
   Date:23.12.19 Time:8.58*/
   string mulby2(string s)
   {
       int temp;
       int carry=0;
       for(int i=s.size()-1;i>=0;i--)
       {
           temp=(s[i]-'0')*2;
           s[i]=((temp+carry)%10)+'0';
           carry=(temp+carry)/10;
       }
     if(carry)
       s.insert(0,1,'0'+carry);
       return s;
   }
   int Solution::power(string A) {
       if(A.size()==1) return A=="2" || A=="4";
       else
       {
           string s="1";
           while(1)
           {
               s=mulby2(s);
               // cout<<s<<endl;
               if (s==A) return 1;
               if (s.size()>A.size()) return 0;
           }
       }

   }
