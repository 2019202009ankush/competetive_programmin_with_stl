#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll> arr(n,0);
        for(ll i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        ll mask = (1<<n ) - 1;
        // cout<<mask<<endl;
        ll k;
        cin>>k;
        ll count  = 0;
        
        while(mask>0)
        {
            ll sum=0;
            for(ll i=0;i<n;i++)
            {
                if(mask>>i & 1 == 1) sum+=arr[i];
            }
            if(sum==k) count++;
            mask--;
        }
        cout<<count<<endl;
        
    }
}