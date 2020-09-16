#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void dfs(ll x,vector<vector<ll>>& graph,vector<ll> & vis,stack<ll> & s)
{
  vis[x]=1;
  for(auto k:graph[x])
  {
    if(vis[k]==0)
    {
        dfs(k,graph,vis,s);
    }
  }
    s.push(x);
}
void dfs1(ll x,vector<vector<ll>>&rgraph,vector<ll> & vis1,set<ll> & s)
{
    vis1[x]=1;
    for(auto k:rgraph[x])
    {
       if(vis1[k]==0)
       {
           dfs1(k,rgraph,vis1,s);
       }
    }
    s.insert(x);
}
    
int main()
{
   while(1)
   {
         ll n,m;
    
         cin>>n;
         if(n==0) break;
         cin>>m;
        vector<ll> vis(n+1,0),vis1(n+1,0);
        vector<vector<ll>> graph(n+1),rgraph(n+1);
        for(ll i=0;i<m;i++)
        {
            ll u ,v;
            cin>>u>>v;
            graph[u].push_back(v);
            rgraph[v].push_back(u);
            
         }
        stack<ll> s;
        for(ll i=1;i<=n;i++)
        {
          if(vis[i]==0)
          {
              dfs(i,graph,vis,s);
          }
        }
        set<ll> ans;
        while(!s.empty())
        {
         ll t = s.top();
            
            s.pop();
            if(vis1[t]==0)
            {
                set<ll> comps  ;
                dfs1(t,rgraph,vis1,comps);
                ll x=0;
                for(auto c:comps)
                {
                   for(auto k:graph[c])
                   {
                       if(comps.find(k)==comps.end())
                       {
                           x=1;
                           break;
                       }
                   }
                    if(x==1) break;
                }
                if(x==0)
                {
                   for(auto k:comps)
                   {
                        ans.insert(k);
                   }
                }
                
                
            }
        }
       for(auto cc: ans)
       {
           cout<<cc<<" ";
       }
       cout<<endl;
       
   }
        
   
}
