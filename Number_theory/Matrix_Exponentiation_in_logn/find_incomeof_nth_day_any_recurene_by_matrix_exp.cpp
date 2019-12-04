#include<bits/stdc++.h>
#define fast std::ios::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define test cout<<"xyz\n"
#define debug(x) cout<<x<<" "
#define debug1(x) cout<<x<<"\n"
#define debug2(x,y) cout<<x<<" "<<y<<"\n"
#define pb push_back
#define pi pair<int,int>
#define fi first
#define si second
#define mod (ll)1000000007
using namespace std;
unsigned ll modExponentiation(unsigned ll a, unsigned ll p)
{
    unsigned ll res=1ULL;
    a%=mod;
    while(p)
    {
        if(p & 1)
        {
            res = (res*a)%mod;
        }
        a = (a%mod * a%mod)%mod;
        p/=2;
    }
    return res;
}
void multiply(unsigned ll a[2][2], unsigned ll m[2][2])
{
    unsigned ll fval, sval, tval, lval;
    fval = ((a[0][0] * m[0][0])%(mod-1) + (a[0][1]*m[1][0])%(mod-1))%(mod-1);
    sval = ((a[0][0]*m[0][1])%(mod-1) + (a[0][1]*m[1][1])%(mod-1))%(mod-1);
    tval = ((a[1][0]*m[0][0])%(mod-1) + (a[1][1]*m[1][0])%(mod-1))%(mod-1);
    lval = ((a[1][0]*m[0][1])%(mod-1) + (a[1][1]*m[1][1])%(mod-1))%(mod-1);
    a[0][0]=fval;
    a[0][1]=sval;
    a[1][0]=tval;
    a[1][1]=lval;
}
void power(unsigned ll a[2][2], unsigned ll n)
{
    // cal a^n by a^n/2 * a^n/2;
    if(n==0 || n==1)
        return;
    power(a, n/2);
    // ab tak a change hoke a^n/2 ban chuka hoga so bs hume uska multiply khud se krna ha.
    multiply(a, a);
    // if n is odd.
    if(n & 1)
    {
        unsigned ll m[2][2] = {{1ULL, 1ULL}, {1ULL, 0ULL}};
        multiply(a, m);
    }
    return;
}
unsigned ll fib(unsigned ll n)
{
    if(n==0)
        return 0;
    unsigned ll a[2][2] = {{1,1}, {1,0}};
    power(a, n-1);
    return a[0][0];
}
int main()
{
    int t; cin>>t;
    unsigned ll n,a,b,x,y,m1,m2,ans;
    while(t--)
    {
        cin>>a>>b>>n;
       
        if(n==0)
        {
          debug1(a); continue;
        }
        a++;b++;
        x = fib(n-1);
        y = fib(n);
        //debug2(x, y);
        // cout<<x<<" "<<y<<endl;
        m1 = modExponentiation(a, x);
        m2 = modExponentiation(b, y);
        // cout<<m1<<" "<<m2<<endl;
        ans = (((m1%mod * m2%mod)%mod) - 1%mod)%mod;
        debug1(ans);
    }
    return 0;
}