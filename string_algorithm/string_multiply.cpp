/* String Multiply
   Writeen By: Ankush Mitra
   Date:24.12.19  Time:12.49*/

   string Solution::multiply(string A, string B) {
       vector<string> intermediate;
       if(A=="0" || B== "0" )
         return "0";
       for(int i=B.size()-1;i>=0;i--)
       {
           if(B[i]!=0)
           {
               string c="";
               // cout<<B[i]<<endl;
               int now=(B[i]-'0');

               int t;
               int carry=0;

               for(int k=A.size()-1;k>=0;k--)
               {
                   t=(A[k]-'0')*now;
                   char temp=((t+carry)%10)+'0';

                   carry=(t+carry)/10;
                   // cout<<"carry="<<carry<<endl;
                   c=temp+c;

               }
               if(carry)
                     c.insert(0,1,'0'+carry);
               for(int j=B.size()-1;j>i;j--)
               {
               c+="0";
               }
               // cout<<c<<endl;
               intermediate.push_back(c);

           }

       }
       string d=intermediate[0];
       for(int k=1;k<intermediate.size();k++)
       {
           string c="";
           // cout<<d<<endl;
           string a=d;
           string b=intermediate[k];

       int i=a.size()-1;
       int j=b.size()-1;
       int carry=0;
       int temp;

       while(i>=0&&j>=0)
       {

           temp=(a[i]-'0')+(b[j]-'0');
           // cout<<temp<<endl;
           // cout<<((temp+carry)%10)<<" "<<carry<<endl;
           char t=((temp+carry)%10)+'0';
           carry=(temp+carry)/10;
           // cout<<"carry="<<carry<<endl;

           // cout<<"t="<<t<<endl;
           c=t+c;
           i--;
           j--;
       }
       while(i>=0)
       {
           temp=(a[i]-'0');
           string t(1,((temp+carry)%10)+'0');
           carry=(temp+carry)/10;

           c=t+c;
           i--;
       }
       while(j>=0)
       {
           temp=(b[j]-'0');
           string t(1,((temp+carry)%10)+'0');
           carry=(temp+carry)/10;

           c=t+c;
           j--;
       }
       if(carry)
       {
          c.insert(0,1,'1');
       }
       d=c;
       }
       int i;
       for(i=0;i<d.size();i++)
       {
           if(d[i]!='0') break;
       }
       return (d.substr(i));
   }
