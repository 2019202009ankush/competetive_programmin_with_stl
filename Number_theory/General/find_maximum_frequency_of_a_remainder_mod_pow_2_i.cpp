#include<bits/stdc++.h>
using namespace std;
string arr[]={"000","001","010","011","100","101","011","111"};
int maxf(string octal)
{
	string b="";
	for(int i=0;i<octal.size();i++)
	{
		b+=arr[octal[i]-'0'];
	}
  b=b.substr(0,b.size()-1);
  int count=1,prev=-1,i,j=0;
  for(int i=b.size()-1;i>=0;i--,j++)
  {
  	if(b[i]=='1')
  	{
  		count=max(count,j-prev);
  		prev=j;
  	}
  }
}
int main()
{

}