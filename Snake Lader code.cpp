/* Problem: Snake Lader code
   Written By: Ankush Mitra
   Date : 1.11.19 Time : 1.52*/
#include <bits/stdc++.h>

using namespace std;

// Complete the quickestWayUp function below.
int quickestWayUp(vector<vector<int>> ladders, vector<vector<int>> snakes) {
  int vis[106]={0};
  int dis[106]={0};
  map<int,int>m;
  for(int i=1;i<=100;i++)
  {
      m[i]=i;
  }
   for(int i=0;i<ladders.size();i++)
   {
      m[ladders[i][0]]=ladders[i][1];
   }
    for(int i=0;i<snakes.size();i++)
    {
      m[snakes[i][0]]=snakes[i][1];
    }
    vis[1]=1;
  queue<int> q;
    memset(vis,0,sizeof(vis));
    memset(dis,0,sizeof(dis));
   q.push(1);
    while(!q.empty())
    {
        int tem=q.front();
        cout<<tem<<endl;
        q.pop();
        for(int i=1;i<7;i++)
        {
            int nnode=m[tem+i];
            if(nnode>=0&&nnode<=100)
            {
            if(vis[nnode]==0)
            {
                vis[nnode]=1;
                dis[nnode]=dis[tem]+1;
                q.push(nnode);
            }
            }
        }
    }
    
    if(vis[100]==0)
          return -1;
    else 
        return dis[100];

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> ladders(n);
        for (int i = 0; i < n; i++) {
            ladders[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> ladders[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int m;
        cin >> m;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> snakes(m);
        for (int i = 0; i < m; i++) {
            snakes[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> snakes[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int result = quickestWayUp(ladders, snakes);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
