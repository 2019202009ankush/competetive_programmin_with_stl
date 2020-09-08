#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
struct node{
  ll sum;
    ll mxsum;
    ll prefix;
    ll sufix;
    node()
    {
        sum=INT_MIN;
        mxsum=INT_MIN;
        prefix=INT_MIN;
        sufix=INT_MIN;
    }
};
vector<node> seg(4000000);
void build(vector<ll> & arr,ll l,ll r, ll tree)
{
   if(l==r)
   {
        seg[tree].sum=seg[tree].mxsum=seg[tree].prefix=seg[tree].sufix=arr[l];
       return;
   }
    ll mid =    (l+r)/2;
    build(arr,l,mid,2*tree+1);
    build(arr,mid+1,r,2*tree+2);
    seg[tree].sum = seg[2*tree+1].sum + seg[2*tree+2].sum;
    seg[tree].prefix = max(seg[2*tree+1].prefix,seg[2*tree+1].sum+seg[2*tree+2].prefix);
    seg[tree].sufix=max(seg[2*tree+2].sufix,seg[2*tree+2].sum+seg[2*tree+1].sufix);
    seg[tree].mxsum = max(seg[tree].prefix,max(seg[tree].sufix,max(seg[2*tree+1].mxsum,max(seg[2*tree+2].mxsum,seg[2*tree+1].sufix+seg[2*tree+2].prefix))));
}
node query(ll l,ll r,ll left,ll right,ll tree)
{
    
    if(left<=l&&r<=right)
    {
        return seg[tree];
    }
    if(l>right||r<left)
    {
       node a=node();
           return a;
    }
    ll mid  = (l+r)/2;
    node ans1= query(l,mid,left,right,2*tree+1);
    auto ans2 =  query(mid+1,r,left,right,2*tree+2);
    node a = node();
    a.sum = ans1.sum + ans2.sum;
    a.prefix = max(ans1.prefix,ans1.sum+ans2.prefix);
    a.sufix=max(ans2.sufix,ans2.sum+ans1.sufix);
    a.mxsum = max(a.prefix,max(a.sufix,max(ans1.mxsum,max(ans2.mxsum,ans1.sufix+ans2.prefix))));
  return a;
}
int main()
{
    ll n;
    cin>>n;
    vector<ll> arr(n,0);
    for(ll i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    build(arr,0,n-1,0);
    ll m;
    cin>>m;
    for(ll i=0;i<m;i++)
    {
     ll l,r;
        cin>>l>>r;
        l--;
        r--;
        cout<<query(0,n-1,l,r,0).mxsum<<endl;
    }
    
}