/* Find largest area of water Choose two bar ignore all other bar find maximum area water tapped in it
  Written By : Ankush Mitra
  Date: 14.12.19 Time:16:52*/
#include<bits/stdc++.h>
using namespace std;
int maxArea(vector<int> &A) {
    // sort(A.begin(),A.end());
    int max_area=INT_MIN;
    if(A.size()<=1)
    {
        return 0;
    }
    int pointer1=0;
    int pointer2=A.size()-1;
    while(pointer1<pointer2)
    {
        max_area=max(max_area,(pointer2-pointer1)*min(A[pointer1],A[pointer2]));
        if(A[pointer1]<A[pointer2])
        {
            pointer1++;
        }
        else
        {
            pointer2--;
        }
    }
    return max_area;
}
