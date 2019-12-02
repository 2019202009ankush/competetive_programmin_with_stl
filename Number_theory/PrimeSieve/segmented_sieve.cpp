/*Print all prime between l to r where r is O(n^10)
  Written by: Ankush Mitra
 Date: 2.12.19 Time:23:59*/
#include<bits/stdc++.h>
using namespace std;
vector<int> prime()
{
    bool primeA[100001];
    memset(primeA,true,sizeof(primeA));
    primeA[0]=false;
    primeA[1]=false;
    for(int i=2;i*i<=100001;i++)
    {
        if(primeA[i])
        {
            for(int j=2*i;j<=100001;j+=i)
            {
                primeA[j]=false;
            }
        }
    }
    vector<int> ans;
    for(int i=2;i<=100001;i++)
    {
        if(primeA[i]) ans.push_back(i);
    }
    return ans;
}
int main()
{
    vector<int>pri;
    pri=prime();
    // for(int i=0;i<pri.size();i++) cout<<pri[i]<<" ";
    
    int t;
    cin>>t;
    while(t--)
    {
        long long int l,r,base;
        cin>>l>>r;
        bool prime[r-l+1];
        memset(prime,true,sizeof(prime));
        for(int i=0;pri[i]*(long long int)pri[i]<=r;i++)
        {
            base=(l/pri[i])*pri[i];
            if(base<l)
            {
                base+=pri[i];
            }
            for(int j=base;j<=r;j+=pri[i])
            {
                prime[j-l]=false;
            }
            if(base==pri[i])
                prime[base-l]=true;
        }
        for(int i=0;i<=r-l;i++)
        {
            if(prime[i])
                cout<<i+l<<endl;
        }
        
    }
    
}
