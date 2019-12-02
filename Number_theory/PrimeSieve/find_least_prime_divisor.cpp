/*Find Least Prime Divisor
  Written By: Ankush Mitra
  Date:2.12.19 Time:10:22*/
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
			for(int j=i+i;j<=n;j+=i)
			{
				if(primeArray[j]==j)
				{
					primeArray[j]=i;
				}
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