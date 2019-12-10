/*Find gcd of big number which is > 10^250 and a small number 10^9
  Written By:Ankush Mitra
  Date: 11.12.19 Time:1:34*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
	// Write your code here
    int t;
    cin>>t;
    while(t--)
    {
    ll a;
        string b;
        cin>>a>>b;
ll num=0;
if(b.size()==1&&b[0]=='0')
{
    cout<<a<<endl;
    continue;
}
for(int i=0;i<b.size();i++)
{
    num=((num%a*10%a +a)%a + (b[i]-'0')%a +a)%a;
}
      cout<<__gcd(a,num)<<endl;

    }
	return 0;
}
