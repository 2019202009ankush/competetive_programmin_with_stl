/*
 * Author: thesigmaguy
 * Date: 31/Oct/2019
 * Possible pairs
*/
#include <cstdio>
#include <vector>
#include <iostream>
#include <utility>
using namespace std;

void merge(vector<pair<int,pair<long long, long long>>>& parent, int p1, int p2)
{
    long long p1_sum_b = parent[p1].second.first;
    long long p1_sum_g = parent[p1].second.second;
    long long p2_sum_b = parent[p2].second.first;
    long long p2_sum_g = parent[p2].second.second;
    if((p1_sum_b+p1_sum_g) >= (p2_sum_g+p2_sum_g))
    {
        parent[p2].first = p1;
        parent[p1].second.first += p2_sum_b;
        parent[p1].second.second += p2_sum_g;
    }
    else
    {
        parent[p1].first = p2;
        parent[p2].second.first += p1_sum_b;
        parent[p2].second.second += p1_sum_g;
    }
}

int find_parent(int ind, vector<pair<int, pair<long long,long long>>>& parent)
{
    vector<int> child;
    while(ind!=parent[ind].first)
    {
        child.push_back(ind);
        ind=parent[ind].first;
    }
    for(auto i:child)
        parent[i].first = ind;
    return ind;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int m,n;
    //parent in first, second->(boy count, girl count)
    vector<pair<int,pair<long long, long long>>> parent;
    cin>>m>>n;
    
    //dummy 0, as indexes start from 1
    parent.push_back(make_pair(0,make_pair(0,0)));

    //m->boys, each boy is in his own group with boy count 1 and girl count 0
    for(int i=1;i<=m;i++)
        parent.push_back(make_pair(i,make_pair(1,0)));
    
    //n->girls, starting after m boys, each girl is in her own group with boy count 0 and girl count 1
    for(int i=m+1;i<=m+n;i++)
        parent.push_back(make_pair(i,make_pair(0,1)));
    
    int c1;
    cin>>c1;
    for(int i=0;i<c1;i++)
    {
        int a,b;
        cin>>a>>b;
        int p1 = find_parent(a,parent);
        int p2 = find_parent(b,parent);
        if(p1!=p2)
            merge(parent, p1, p2);
    }
    
    int c2;
    cin>>c2;
    for(int i=0;i<c2;i++)
    {
        int a,b;
        cin>>a>>b;
        a+=m;
        b+=m;
        int p1 = find_parent(a,parent);
        int p2 = find_parent(b,parent);
        if(p1!=p2)
            merge(parent, p1,p2);
    }
    
    int c3;
    cin>>c3;
    for(int i=0;i<c3;i++)
    {
        int a,b;
        cin>>a>>b;
        b+=m;
        int p1=find_parent(a,parent);
        int p2=find_parent(b,parent);
        if(p1!=p2)
            merge(parent, p1,p2);
    }
    long long res = 0;
    
    for(int i=0;i<m+n;i++)
        if(i==parent[i].first)
            res+=(parent[i].second.first *(n- parent[i].second.second));

    cout<<res<<endl;
    return 0;
}
