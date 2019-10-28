/* BellManFord code 
   Written by: Ankush Mitra
   Date: 28.10.9 Time: 5.03 P.M*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> Des_We_pair;
typedef pair<int,Des_We_pair>edge;
vector<edge>graph;
int main(){
	int no_of_node,no_of_edges;
	cin>>no_of_node>>no_of_edges;
	while(no_of_edges--)
	{
		int sou,des,w;
		cin>>sou>>des>>w;
		Des_We_pair t=make_pair(des,w);
		edge e=make_pair(sou,t);
		graph.push_back(e);//Making the edge list for the graph

	}
	int * dp_des=new int[no_of_node];
	for(int i=0;i<no_of_node;i++)
	{
		dp_des[i]=INT_MAX;
	}
    int strating_node;
    cin>>strating_node;
    dp_des[strating_node]=0;
    for(int i=0;i<no_of_node-1;i++)//relax the edges |v|-1 times
    {
    	for(int j=0;j<graph.size();j++)
    	{
    		int sou=graph[j].first;
    		int des=graph[j].second.first;
    		int weight=graph[j].second.second;
    		if(dp_des[sou]!=INT_MAX&&dp_des[des]>dp_des[sou]+weight)
    		{
    			dp_des[des]=dp_des[sou]+weight;
    		}
    	}
    }
    bool is_negative_weight_cycle=false;
    for(int j=0;j<graph.size();j++)//Relax one more time to detect the negative weight cycle
	{
		int sou=graph[j].first;
		int des=graph[j].second.first;
		int weight=graph[j].second.second;
		if(dp_des[sou]!=INT_MAX&&dp_des[des]>dp_des[sou]+weight)
		{
			is_negative_weight_cycle=true;
		}
	}
	int des;
	cin>>des;
	if(is_negative_weight_cycle)
		cout<<"-1"<<endl;
	else
		cout<<dp_des[des]<<endl;
	

}