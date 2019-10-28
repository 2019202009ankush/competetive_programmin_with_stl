/*Program for Dijsktra Single Source Shortest Path
  Written by : Ankush Mitra
  Date: 28.10.19 Time: 3.00 P.M */
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> Des_Weight_Pair;
typedef pair<ll,ll> relaxedVal_node_Pair;//For relaxing ,   intially source  is already relaxed to 0

vector<Des_Weight_Pair>graph[100009];
ll vis[100009];
ll dis[100009];

void init()
{
	for(int i=0;i<100009;i++)
	{
		graph[i].clear();
		vis[i]=0;
		dis[i]=INT_MAX;
	}
}
int main()
{
	ll no_of_test_case;
	cin>>no_of_test_case;
	while(no_of_test_case--)
	{
		void init();
		ll no_of_node,no_of_edges;
		cin>>no_of_node>>no_of_edges;
		for(ll i=0;i<no_of_edges;i++)
		{
			ll Source,Des,Weight;
			cin>>Source>>Des>>Weight;
			graph[Source].push_back({Des,Weight});//Making the Adjacency List
		}
	    multiset<relaxedVal_node_Pair>DijsktraHeap;
	    DijsktraHeap.insert({0,1});  //Asumming the statring node is 1
	    dis[1]=0;
	    while(!DijsktraHeap.empty())
	    {
	    	Des_Weight_Pair tem=*DijsktraHeap.begin();
	    	DijsktraHeap.erase(DijsktraHeap.begin());
	    	
	    	ll tem_node=tem.second;
	    	if(vis[tem_node]==1)
	    		continue;
	    	vis[tem_node]=1;
	    	for(int i=0;i<graph[tem_node].size();i++)
	    	{
	    		Des_Weight_Pair new_node_pair=graph[tem_node][i];
	    		ll new_node=new_node_pair.first;
	    		ll w=new_node_pair.second;
	    		if(dis[new_node]>dis[tem_node]+w)
	    		{
	    			dis[new_node]=dis[new_node]+w;
	    			DijsktraHeap.insert({dis[new_node],new_node});
	    		}
                
	    	}

    	}
    	ll final_des;
    	cin>>final_des;
    	cout<<dis[final_des]<<endl;
    	
	}
	
}