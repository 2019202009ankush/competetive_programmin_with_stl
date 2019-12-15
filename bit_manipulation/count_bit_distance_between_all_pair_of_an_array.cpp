/*Count bit difference between all pair of an array
 Written By :Ankush Mitra
 Date:15.12.19 Time:15.34*/

int cntBits(vector<int> &A) {
    long long sum,mod=1e9+7;
    int n=A.size();
    for(int i=0;i<32;i++)
    {
          long long count=0;
          for(int k=0;k<A.size();k++)
          {
              if(A[k]&(1<<i)) count++;//check for i th bit is 1 or not if it is one then increment the count

          }
          sum=(sum%mod + (2*count*(n-count))%mod +mod )%mod;
    }
    return sum;
}
