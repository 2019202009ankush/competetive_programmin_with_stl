#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef struct node{
ll ss;
ll s;
    node()
    {
       ss=0;
        s=0;
    }
}node;
typedef struct lazy_node{
    ll set;
    ll update;
    lazy_node()
    {
       set=0; 
        update=0;
    }
}lazy_node;
vector<node> seg(4000000);
vector<lazy_node> lazy(4000000);
void build(vector<ll> & arr,ll l ,ll r,ll tree)
{
   if(l==r)
   {
     seg[tree].ss=arr[l]*arr[l];
       seg[tree].s = arr[l];
      return;
   }
    ll   mid  =  (l+r)/2;
    build(arr,l,mid,2*tree+1);
    build(arr,mid+1,r,2*tree+2);
    seg[tree].ss = seg[2*tree+1].ss +  seg[2*tree+2].ss;
    seg[tree].s   = seg[2*tree+1].s + seg[2*tree+2].s;
    
}
void update(ll l,ll r,ll left,ll right,ll qtype,ll val,ll tree)
{
    if(l>r) return;
    if(lazy[tree].set!=0)
    {
        ll x = lazy[tree].set;
        seg[tree].ss = x*x*(r-l+1);
        seg[tree].s  = x*(r-l+1);
        if(l!=r)
        {
             lazy[2*tree+1].set  = x;
             lazy[2*tree+2].update = 0;
             lazy[2*tree+2].set  = x;
             lazy[2*tree+2].update = 0;
        }
         lazy[tree].set=0;
        
    }
    if(lazy[tree].update!=0)
    {
        ll x = lazy[tree].update;
        seg[tree].ss += x*x*(r-l+1) + 2*x* seg[tree].s;
        seg[tree].s  += x*(r-l+1);
        if(l!=r)
        {
             lazy[2*tree+1].update  += x;
            
             lazy[2*tree+2].update  += x;
             
        }
         lazy[tree].update=0;
    }
    if(left<=l&&r<=right)
    {
      if(qtype==1)
      {
          seg[tree].ss = val*val*(r-l+1);
          seg[tree].s  = val*(r-l+1);
          if(l!=r)
          {
             lazy[2*tree+1].set  = val;
             lazy[2*tree+2].update = 0;
             lazy[2*tree+2].set  = val;
             lazy[2*tree+2].update = 0;
          }
          return;
      }
      else {
          seg[tree].ss += val*val*(r-l+1)+ 2*val* seg[tree].s;
          seg[tree].s  += val*(r-l+1);
          if(l!=r)
         {
             lazy[2*tree+1].update  += val;
            
             lazy[2*tree+2].update  += val;
             
        }
       return;
      }
    }
    else if(l>right||r<left) return;
    ll mid = (l+r)/2;
    update(l,mid,left,right,qtype,val,2*tree+1);
    update(mid+1,r,left,right,qtype,val,2*tree+2);
    seg[tree].ss = seg[2*tree+1].ss +  seg[2*tree+2].ss;
    seg[tree].s   = seg[2*tree+1].s + seg[2*tree+2].s;
    
}
ll query(ll l ,ll r,ll left,ll right,ll tree)
{
    if(lazy[tree].set!=0)
    {
        ll x = lazy[tree].set;
        seg[tree].ss = x*x*(r-l+1);
        seg[tree].s  = x*(r-l+1);
        if(l!=r)
        {
             lazy[2*tree+1].set  = x;
             lazy[2*tree+2].update = 0;
             lazy[2*tree+2].set  = x;
             lazy[2*tree+2].update = 0;
        }
         lazy[tree].set=0;
        
    }
    if(lazy[tree].update!=0)
    {
        ll x = lazy[tree].update;
        seg[tree].ss += x*x*(r-l+1) + 2*x* seg[tree].s;
        seg[tree].s  += x*(r-l+1);
        if(l!=r)
        {
             lazy[2*tree+1].update  = x;
            
             lazy[2*tree+2].update  = x;
             
        }
         lazy[tree].update=0;
    }
    if(left<=l&&r<=right)
    {
      return seg[tree].ss;
    }
    if(l>right||r<left) return 0;
    ll mid = (l+r)/2;
    ll ans1 = query(l,mid,left,right,2*tree+1);
    ll ans2 = query(mid+1,r,left,right,2*tree+2);
    return ans1+ans2;
}
int main()
{
    ll t;
    cin>>t;
    for(ll k=0;k<t;k++)
    {
        cout<<"Case "<<k+1<<":"<<endl;
        ll n;
        ll m;
        cin>>n;
        cin>>m;
        vector<ll> arr(n,0);
        for(ll i=0;i<n;i++) cin>>arr[i];
        build(arr,0,n-1,0);
        // cout<<"here"<<endl;
        for(ll i=0;i<m;i++)
        {
           int ty;
            cin>>ty;
            if(ty==0)
            {
                ll l,r,val;
                cin>>l>>r>>val;
                l--;
                r--;
                update(0,n-1,l,r,1,val,0);
            }
            else if(ty==1)
            {
                 ll l,r,val;
                cin>>l>>r>>val;
                l--;
                r--;
                update(0,n-1,l,r,2,val,0);
            }
            else
            {
                ll l,r;
                cin>>l>>r;
                l--;
                r--;
                cout<<query(0,n-1,l,r,0)<<endl;
            }
        }
    }
}
