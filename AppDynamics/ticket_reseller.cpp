/* ticket reselling
  Written By:Ankush Mitra
 Date:7.1.20 Time:19.19*/
 #include<bits/stdc++.h>
 using namespace std;

 int main() {
 	//code
 	int t;
 	cin>>t;
 	while(t--)
 	{
 	    int n,k;
 	    cin>>n>>k;
 	    priority_queue<int>q;
 	    for(int i=0;i<n;i++)
 	    {
 	       int p;
 	       cin>>p;
 	       q.push(p);
 	    }
 	    int sum=0;
 	    while(k--&&!q.empty())
 	    {
 	        int h=q.top();
 	       // cout<<h<<" "<<k<<endl;
 	        q.pop();
 	        sum+=h;
 	        q.push(h-1);


 	    }
 	    cout<<sum<<endl;
 	}
 	return 0;
 }
