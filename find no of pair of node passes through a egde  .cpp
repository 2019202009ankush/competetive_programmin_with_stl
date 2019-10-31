/* Problem : find no of pair of node passes through some edge
   Written By: Ankush Mitra
   Date: 1.11.19 Time: 2.35*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector<ll>graph[100009];
ll vis[100009];
ll no_node_at_subtree[100009];
    map<ll,pair<ll,ll>>Encoder;
ll dfs(ll node)
{
    vis[node]=1;
    // cout<<"node="<<node<<endl;
    ll no_n=0;
    for(ll i=0;i<graph[node].size();i++)
    {
        ll el=graph[node][i];
        if(vis[el]==0)
        {
            no_n+=dfs(el);
        }
    }
    no_node_at_subtree[node]=no_n+1;
    return no_node_at_subtree[node];
}
int main()
{
    ll n,q;
    cin>>n>>q;
        memset(vis,0,sizeof(vis));
     // cout<<n<<" "<<q<<endl;  
    for(ll i=1;i<=n-1;i++)
    {
        ll l,r;
        cin>>l>>r;
        graph[l].push_back(r);
      graph[r].push_back(l);
          Encoder[i]={l,r};
        
    }
    dfs(1);
    while(q--)
    {
        ll nthedge;
        cin>>nthedge;
        pair<ll,ll>p=Encoder[nthedge];
        ll sub_tree_at_first=no_node_at_subtree[p.first];
        ll sub_tree_at_second=no_node_at_subtree[p.second];
        ll ans=min(sub_tree_at_first,sub_tree_at_second);
            ans=ans*(n-ans);
      cout<<ans<<endl;
        
    }
    
}
