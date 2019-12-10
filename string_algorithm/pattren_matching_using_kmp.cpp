/* Pattren Searching Using KMP
   Written By: Ankush Mitra
   Date:11.12.19 Time:00:43*/
   // S and T - input strings
   // You need to check if string T is present in S or no
   #include<bits/stdc++.h>
   using namespace std;
   vector<int> LPS(char T[])
   {
       int i=1;
       int j=0;
       vector<int> lps(strlen(T));
       lps[0]=0;
       while(i<strlen(T))
       {
           if(T[i]==T[j])
           {
               lps[i]=j+1;
               i++;
               j++;
           }
           else
           {
               if(j==0)
               {
                   lps[i]=0;
                   i++;
               }
               else
               {
                   j=lps[j-1];
               }
           }
       }
       return lps;
   }
   int findString(char S[], char T[]) {
       // Write your code here
       vector<int>lps=LPS(T);
       int i=0;
       int j=0;
       while(i<strlen(S)&&j<strlen(T))
       {
           if(S[i]==T[j])
           {
               i++;
               j++;
           }
           else{
               if(j==0)
               {
                   i++;
               }
               else
               {
                   j=lps[j-1];
               }
           }

       }
         if(j==strlen(T))
               return i-j;
       else
           return -1;


   }
int main()
{
  int n,m;
  cin>>n>>m;
  char S[n+1],T[m+1];
 S[n]='\0';
 T[m]='\0';
 for(int i=0;i<n;i++)
 {
 cin>>S[i];
 }
 for(int i=0;i<m;i++)
 {
   cin>>T[i];
 }
 cout<<findString(S,T);
}
