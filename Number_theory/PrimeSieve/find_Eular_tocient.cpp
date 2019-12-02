/*Find Eular Toicient
  Written By: Ankush Mitra
  Date:2.12.19 Time:10:33*/
#include<bits/stdc++.h>
using namespace std;
void prime(int n)
{
	int primeArray[n+1];
	for(int i=1;i<=n;i++)
		primeArray[i]=i;
	
	for(int i=2;i<=n;i++)
	{
		if(primeArray[i]==i)
		{
			primeArray[i]=i-1;
			for(int j=i+i;j<=n;j+=i)
			{
				primeArray[j]=(primeArray[j]*(i-1))/i;
			}
		}
	}
	for(int i=2;i<=n;i++)
	{
		cout<<primeArray[i]<<" ";
	}
	cout<<endl;
}
int main()
{
	int n;
	cin>>n;
	prime(n);

}