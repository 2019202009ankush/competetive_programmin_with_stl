/* Floyd Warshal code 
   Written by: Ankush Mitra
   Date: 28.10.9 Time: 4.03 P.M*/

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
map<string,int> Encoder;
int main()
{
	    ll no_of_node,no_of_edges:
		cin>>no_of_node>>no_of_edges;
		count=0;
		while(no_of_node--)
		{
			string node;
			cin>>node;
			Encoder[node]=count;//Encode the string to some numeric value
			count=count+1;
		}
	    int  ** AdjacencyMatrix=new int*[no_of_node];
	    for(int i=0;i<no_of_node;i++)
	    {
	    	AdjacencyMatrix[i]=new int [no_of_node];
	    }
	    for(int i=0;i<no_of_node;i++)
	    {
	    	for(int j=0;j<no_of_node;j++)
	    	{
	    		AdjacencyMatrix[i][j]=INT_MAX;
	    	}
	    }
	    for(int i=0;i<no_of_node;i++)
	    {
	    	AdjacencyMatrix[i][i]=0;//Diagonal Element distance is 0
	    }
		while(no_of_edges--)
		{
			string sou,des;
			ll  weight;
			cin>>sou>>des>>weight;
			AdjacencyMatrix[Encoder[sou]][Encoder[des]]=weight;// Making the adjacency matrix
			AdjacencyMatrix[Encoder[des]][Encoder[sou]]=weight;// for undirected graph
		}
		for(ll k=0;k<no_of_node;k++)
		{
			for(ll i=0;i<no_of_node;i++)
			{
				for(ll j=0;j<no_of_node;j++)
				{
					if(AdjacencyMatrix[i][j]>AdjacencyMatrix[i][k]+AdjacencyMatrix[k][j])
					{
						AdjacencyMatrix[i][j]=AdjacencyMatrix[i][k]+AdjacencyMatrix[k][j];
					}
				}
			}
			}
	        int no_of_test;
			cin>>no_of_test;
			while(no_of_test--)
			{
				string sou,des;
				cin>>sou>>des;
				cout<<AdjacencyMatrix[Encoder[sou]][Encoder[des]]<<endl;

			}


}
