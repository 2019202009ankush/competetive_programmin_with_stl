/*Find All Prime No
  Written By: Ankush Mitra
  Date:2.12.19 Time:10:22*/
#include<bits/stdc++.h>
using namespace std;
void prime(int n)
{
	bool primeArray[n+1];
	for(int i=2;i<=n;i++)
		primeArray[i]=true;
	primeArray[1]=false;
	primeArray[0]=false;
	for(int i=2;i*i<=n;i++)
	{
		if(primeArray[i])
		{
			for(int j=i+i;j<=n;j+=i)
			{
				primeArray[j]=false;
			}
		}
	}
	for(int i=2;i<=n;i++)
	{
		if(primeArray[i])
			  cout<<i<<" ";
	}
	cout<<endl;
}
int main()
{
	int n;
	cin>>n;
	prime(n);

}