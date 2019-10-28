/* Anagram Checking By Encoding
   Written By: Ankush Mitra
   Date:28.10.19 Time: 18:18*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    
    int t;
    cin>>t;
    while(t--)
    {
       string u,v;
        cin>>u;
        cin>>v;
      int sum1=0,sum2=0;
      if(u.size()!=v.size())
      {
          cout<<"NO\n";//if size not same then they can't be anagram
          continue;
      }
        
      for(int i=0;i<u.size();i++)
      {
          sum1+=pow(2,u[i]-'a');//"Encode"
      }
        for(int i=0;i<v.size();i++)
        {
            sum2=sum2+pow(2,v[i]-'a');//"Encode"
        }
        if(sum1==sum2)
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }
    return 0;
}
