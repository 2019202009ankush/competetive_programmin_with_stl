/*
 * Author : thesigmaguy
 * Date : 1 Nov 2019
 * Problem : find nCr with mod 1e9+7
 */

#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
long MOD = 1e9+7;

int gcd_eu(int value, int b, int *x1, int *y1)
{
    if(value==0)
    {
        *x1 = 0;
        *y1 =1;
        return b;
    }
    int x2,y2;
    int gcd=gcd_eu(b%value,value,&x2,&y2);
    *x1 = y2-(b/value)*x2;
    *y1 = x2;
    return gcd;
}

int inverse(int value)
{
    int x1,y1;
    if(gcd_eu(value,MOD, &x1,&y1)==1)
    {
        return (x1%MOD+MOD)%MOD;
    }
    return -1;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    long long fact[1000001];
    fact[0]=1;
    for(int i=1;i<1000001;i++)
        fact[i] = (i*fact[i-1])%MOD;
    
    int t=-1;
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        // cout<<inverse(fact[b])<<" "<<inverse(fact[a-b])<<endl;
        cout<<(((fact[a]*inverse(fact[b]))%MOD)*inverse(fact[a-b]))%MOD<<endl;
    }
    
    return 0;
}

