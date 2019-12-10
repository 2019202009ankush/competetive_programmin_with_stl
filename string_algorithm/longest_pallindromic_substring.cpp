/* Longest pallindromic Substring
   Written By:Ankush Mitra
   Date:11.12.19 Time:00:43*/
   #include<bits/stdc++.h>
   using namespace std;
   int countPalindromeSubstrings(char s[]) {
   	// Write your code here
       int maxi=0;
       for(int i=0;i<strlen(s);i++)
       {
           //odd
           int l=i;
           int r=i;
           while(l>=0&&r<strlen(s)&&s[l]==s[r])
           {
               int curr_len=r-l+1;
               maxi=max(maxi,curr_len);
               l++;
               r--;
           }
           //even
           l=i;
           r=i+1;
           while(l>=0&&r<strlen(s)&&s[l]==s[r])
           {
               int curr_len=r-l+1;
               maxi=max(maxi,curr_len);
               l++;
               r--;
           }

       }
       return maxi;

   }
  int main()
  {
    int n;
    cin >>n;
    char s[n+1];
    s[n]='\0';
    for(int i=0;i<n;i++)
    {
      cin>>s[i];
    }
    cout<<countPalindromeSubstrings(s)<<endl;
  }
