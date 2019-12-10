/*Find divisor of factorial
  Written By:Ankush Mitra
  Date:11.12.19 Time:1:36*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod=1e9+7;
vector<int> pRime()
{
      bool prime[500006];
     memset(prime,true,sizeof(prime));
    prime[0]=false;
    prime[1]=false;
    for(int i=2;i*i<=500005;i++)
    {
        if(prime[i]==true)
        for(int j=2*i;j<=500005;j+=i)
        {
            prime[j]=false;
        }
    }
    vector<int> ans;
    for(int i=0;i<=500005;i++)
    {
        if(prime[i]) ans.push_back(i);
    }
    return ans;
}
int main(){
	// Write your code here
    vector<int> prime= pRime();
    // cout<<prime.size()<<endl;
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        if(n==0||n==1)
        {
            cout<<"1"<<endl;
            continue;
        }
        vector<int>ans_arry;
        ll ans=1;
        for(int i=0;prime[i]<=n;i++)
        {
           int sum=0;
            int p=prime[i];
            int count=1;

          while((n/p)>0)
          {
              sum+=(n/p);
             p=p*prime[i];
          }

        ans=(ans%mod * (sum+1)%mod)%mod;

        }
        cout<<ans<<endl;

    }
	return 0;
}
