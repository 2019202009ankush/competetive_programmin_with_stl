/* Problem : find unknown ith digit in the seq of number
   Written By: Ankush Mitra 
   Date: 1.11.19 Time: 1.48 */
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    long a[14];
    for(int i=0;i<14;i++)
        a[i] = i*pow(10,i-1)*9;
    long b[14];
    b[0] = a[0];
    for(int i=1;i<14;i++)
        b[i]=(b[i-1]+a[i]);
    int t;
    cin>>t;
    while(t--)
    {
        long k = -1;
        cin>>k;
        long cls = lower_bound(b, b+14, k) - b;
        long val = k;
        if(cls)
            val-=b[cls-1];
        long rem=val%cls;
        val=val/cls;
        val += pow(10,cls-1);
        if(rem==0)
            cout<<to_string(val-1)[to_string(val-1).length()-1]<<endl;
        else
            cout<<to_string(val)[rem-1]<<endl;
    }
    return 0;
}
