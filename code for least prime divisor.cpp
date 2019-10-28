/* code for least prime divisor where n>2 and n<1000000
   written by : ankush mitra
   date : 28.10.19 time: 23.03 */
#include<bits/stdc++.h>
using namespace std;
vector<long long>prime(1000009,-1);
void primeSieve()
{
    for(long long i=2;i<1000009;i++)
    {
        if(prime[i]==-1)
        {
            for(long long j=i;j<1000009;j+=i)
            {
                if(prime[j]==-1)
                    prime[j]=i;
            }
        }
    }
    prime[0]=0;
    prime[1]=0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long q;
    primeSieve();
    cin>>q;
    while(q--)
    {
        long long number;
        cin>>number;
        cout<<prime[number]<<endl;
    }
}
