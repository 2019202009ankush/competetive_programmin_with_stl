#include<bits/stdc++.h>
#include<cstring>
using namespace std;
int dx[8]={1,1,0,-1,-1,-1,0,1};
int dy[8]={0,1,1,1,0,-1,-1,-1};
int vis[11][11];
int n;
int m;
int arr[11][11];
int c=0;
void dfs(int x,int y)
{
    vis[x][y]=1;
    c++;
    for(int i=0;i<8;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0&&nx<n&&ny>=0&&ny<m&&arr[nx][ny]==1&&vis[nx][ny]==0)
        {
            dfs(nx,ny);
        }
    }
}
int main()
{
   cin>>n>>m;
   memset(arr,0,sizeof(arr));
   memset(vis,0,sizeof(vis));
  for(int i=0;i<n;i++)
  {
      for(int j=0;j<m;j++)
      {
          cin>>arr[i][j];
      }
  }
  int global_max=0;
  for(int i=0;i<n;i++)
  {
      for(int j=0;j<m;j++)
      {
          if(arr[i][j]==1&&vis[i][j]==0)
          {
              c=0;
              dfs(i,j);
              int ll=c;
              c=0;
             global_max=max(global_max,ll);
              
          }
      }
  }
 cout<<global_max<<endl;
}
