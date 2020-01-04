/* Find the rank of the string
  Written By:Ankush Mitra
  Date:23.18 Time:23.18*/
  int mod=1e6+3;
int fact(int n)
{
    if(n<=1) return 1;
    else return (n%mod*fact(n-1)%mod)%mod;
}
int Solution::findRank(string A) {

    string b=A;
    sort(b.begin(),b.end());
    int count=1;
    for(int i=0;i<A.size();i++)
    {
        int j=b.find(A[i]);
        count=(count%mod + (j%mod*fact(A.size()-i-1)%mod)%mod)%mod;
        b.erase(b.begin()+j);
    }
    return count;

}
