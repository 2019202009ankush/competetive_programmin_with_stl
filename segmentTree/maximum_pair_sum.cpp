#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef struct node{
    int mx1;
    int mx2;
    node()
    {
     mx1=INT_MIN;
     mx2=INT_MIN;
    }
}node;
vector<node> seg(4000000);
void build_seg(vector<ll>&arr,ll l,ll r,ll tree)
{
  if(l==r)
  {
    seg[tree].mx1=arr[l];
      seg[tree].mx2=INT_MIN;
      return;
  }
    ll mid = (l+r)/2;
    build_seg(arr,l,mid,2*tree+1);
    build_seg(arr,mid+1,r,2*tree+2);
    seg[tree].mx1 = max(seg[2*tree+1].mx1,seg[2*tree+2].mx1);
    seg[tree].mx2 = min(max(seg[2*tree+1].mx1,seg[2*tree+2].mx2) , max(seg[2*tree+2].mx1,seg[2*tree+1].mx2));
  
}
void update(vector<ll>&arr,ll l,ll r,ll idx ,ll val,ll tree)
{
  if(l==r)
  {
     seg[tree].mx1=val;
      seg[tree].mx2=INT_MIN;
      arr[idx]= val;
      return;
  }
    ll mid =(l+r)/2;
    if(idx>mid)
    {
       update(arr,mid+1,r,idx,val,2*tree+2);
    }
    else
    {
        update(arr,l,mid,idx,val,2*tree+1);
    }
    seg[tree].mx1 = max(seg[2*tree+1].mx1,seg[2*tree+2].mx1);
    seg[tree].mx2 = min(max(seg[2*tree+1].mx1,seg[2*tree+2].mx2) , max(seg[2*tree+2].mx1,seg[2*tree+1].mx2));

}
pair<ll,ll>  query(ll l,ll r,ll left , ll right,ll tree)
{
  if(left<=l&&r<=right) return {seg[tree].mx1 , seg[tree].mx2};
  else if(l>right||r<left)  return {INT_MIN,INT_MIN};
  ll mid = (l+r)/2;
    auto ans1 = query(l,mid,left,right,2*tree+1);
    auto ans2 = query(mid+1,r,left,right,2*tree+2);
    ll mx1 = max(ans1.first,ans2.first);
    ll mx2 = min(max(ans1.first,ans2.second) , max(ans2.first,ans1.second));
    // cout<<mx1<<" "<<mx2<<" "<<l<<" "<<r<<endl;
    return {mx1,mx2};

}
// vector<node> seg(4000000);
int main()
{
    ll t;
    cin>>t;
    vector<ll> arr(t,0);
    for(ll i=0;i<t;i++)
    {
        cin>>arr[i];
    }
    build_seg(arr,0,t-1,0);
    // for(ll i=0;i<2*t;i++)
    // {
    //     cout<<seg[i].mx1<<" "<<seg[i].mx2<<endl;
    // }
    ll m;
    cin>>m;
    for(ll i=0;i<m;i++)
    {
        char q;
        cin>>q;
        if(q=='Q')
        {
           ll   l;
            ll r;
            cin>>l>>r;
            l--;
            r--;
            auto ans = query(0,t-1,l,r,0);
            cout<<ans.first+ans.second<<endl;
        }
        else
        {
            ll l;
            ll r;
            cin>>l>>r;
            l--;
            update(arr,0,t-1,l,r,0);
        }
    }
}