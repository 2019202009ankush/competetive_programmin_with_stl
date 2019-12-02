/*Find LCM SUM uisng  Eular Toicient
  Written By: Ankush Mitra
  Date:2.12.19 Time:10:59*/
#include<bits/stdc++.h>
using namespace std;
int prime(int n)
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
	long sum=0;
	for(int i=1;i<=n;i++)
	{
		if(n%i==0)
		sum+=primeArray[i]*i;
	}
	return sum;
}
int main()
{
	int n;
	cin>>n;
	long ans=prime(n);
	ans+=1;
	ans*=n;
	cout<<ans/2<<endl;

}