/*Program to find n th fibbonacci in O(log n)
  Written By:Ankush Mitra
  Time: 16.46 Date: 4.12.19*/

#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;
ll mod=1e9+7;
int main()
{
    ll te,n,p,q,r,s,p1,q1,r1,s1;
    cin>>te;
    while(te--)
    {
        cin>>n;
        n=n-1;
        ll base[2][2]={{1,1},{1,0}};
        ll res[2][2]={{1,0},{0,1}};
        while(n>0)
        {
            if(n%2==1)
            {
                p=res[0][0];
                q=res[0][1];
                r=res[1][0];
                s=res[1][1];
                p1=base[0][0];
                q1=base[0][1];
                r1=base[1][0];
                s1=base[1][1];
                res[0][0]=((((p%mod)*(p1%mod)%mod)%mod)+(((q%mod)*(r1%mod)%mod)%mod)%mod)%mod;
                res[0][1]=((((p%mod)*(q1%mod)%mod)%mod)+(((q%mod)*(s1%mod)%mod)%mod)%mod)%mod;
                res[1][0]=((((r%mod)*(p1%mod)%mod)%mod)+(((s%mod)*(r1%mod)%mod)%mod)%mod)%mod;
                res[1][1]=((((r%mod)*(q1%mod)%mod)%mod)+(((s%mod)*(s1%mod)%mod)%mod)%mod)%mod;
                
            }
                p=base[0][0];
                q=base[0][1];
                r=base[1][0];
                s=base[1][1];
                p1=base[0][0];
                q1=base[0][1];
                r1=base[1][0];
                s1=base[1][1];
                base[0][0]=((((p%mod)*(p1%mod)%mod)%mod)+(((q%mod)*(r1%mod)%mod)%mod)%mod)%mod;
                base[0][1]=((((p%mod)*(q1%mod)%mod)%mod)+(((q%mod)*(s1%mod)%mod)%mod)%mod)%mod;
                base[1][0]=((((r%mod)*(p1%mod)%mod)%mod)+(((s%mod)*(r1%mod)%mod)%mod)%mod)%mod;
                base[1][1]=((((r%mod)*(q1%mod)%mod)%mod)+(((s%mod)*(s1%mod)%mod)%mod)%mod)%mod;
            n=n/2;
        }
        cout<<res[0][0]%mod<<endl;
    }
}
