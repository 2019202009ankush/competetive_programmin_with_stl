/*
 * Author : thesigmaguy
 * Date : Nov 1st 2019
 * Problem : Find Maximum Connected Island
 */
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <climits>
using namespace std;

int dx[8] = {1,0,-1,0,1,-1,1,-1};
int dy[8] = {0,1,0,-1,1,-1,-1,1};


void dfs(int** matrix, int i, int j, long *local_max, bool ** visited, int m, int n)
{
    visited[i][j] = true;
    (*local_max)++;
    for(int k=0;k<8;k++)
    {
        int new_x = dx[k]+i;
        int new_y = dy[k]+j;
        if( (new_x<m && new_x>=0) && (new_y<n && new_y>=0) && !visited[new_x][new_y] && matrix[new_x][new_y])
            dfs(matrix, new_x, new_y, local_max, visited, m, n);
    }
    return;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int m,n;
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>m>>n;

    int **matrix = (int**)calloc(sizeof(int*), m);
    bool **visited = (bool**)calloc(sizeof(bool*), m);
    for(int i=0;i<m;i++)
        matrix[i] = (int*)calloc(sizeof(int), n), visited[i]=(bool*)calloc(sizeof(bool), n);

    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
        {
            cin>>matrix[i][j];
            visited[i][j] = false;
        }

    long global_max = INT_MIN;

    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            if(matrix[i][j] && !visited[i][j])
            {
                long local_max = 0;
                dfs(matrix,i,j,&local_max, visited, m,n);
                global_max = max(global_max, local_max);
            }

    for(int i=0;i<m;i++)
        free(matrix[i]),free(visited[i]);
    free(matrix);
    free(visited);

    cout<<((global_max==INT_MIN)?0:global_max)<<endl;
    return 0;
}
