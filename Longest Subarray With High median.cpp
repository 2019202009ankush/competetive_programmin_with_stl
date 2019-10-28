/* Longest Subarray With High median
   Written by: Ankush Mitra
   Date : 29.10.19 Time : 00.27 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int LengthOfLongestSubarrayWithMaxMean(vector<int>&arr)
{
    int m=0;
    for(int i=1;i<arr.size();i++)
    {
        //cout<<arr[i]<<" "<<((arr[i]+arr[i-1])/2)<<endl;
        if(m<(arr[i]+arr[i-1])/2)
            m=(arr[i]+arr[i-1])/2;
    }
    //cout<<"m="<<m<<endl;
    int global_maxima=0;
    int local_maxima=0;
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]>=m){
          local_maxima++;
            if(global_maxima<local_maxima)
            {
                global_maxima=local_maxima;
            }
        }
        else
            local_maxima=0;
        
    }
    return global_maxima;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++)
    {
        int m;
        cin>>m;
        arr.push_back(m);
    }
    cout<<LengthOfLongestSubarrayWithMaxMean(arr);
    return 0;
}
