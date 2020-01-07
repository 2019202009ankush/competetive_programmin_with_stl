/* Maximum sum after negetion
 k times
 written by:ankush Mitra
 Date:5.1.20 TIme:15.02*/
 #include <bits/stdc++.h>
 using namespace std;

 int main() {

 	int t,n,k;
 	cin>>t;
 	while(t--)
 	{
 	    cin>>n>>k;
 	    int *arr=new int[n];
 	    for(int i=0;i<n;i++)
 	    {
 	        cin>>arr[i];
 	    }
 	    for(int i=0;i<k;i++)
 	    {
 	        int mn=INT_MAX;
 	        int idx=-1;
 	        for(int i=0;i<n;i++)
 	        {
 	            if(mn>arr[i])
 	            {
 	                mn=arr[i];
 	                idx=i;
 	            }
 	        }
 	        if(mn==0)
 	          break;
 	        arr[idx]=-arr[idx];

 	    }
 	    int sum=0;
 	    for(int i=0;i<n;i++)
 	    {
 	        sum+=arr[i];

 	    }
 	    cout<<sum<<endl;
 	}

 	return 0;
 }
