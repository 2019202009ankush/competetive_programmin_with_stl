/* Rain Water trapping
  Written By:Ankush mitra
  Date:30.12.19 Time:15.46*/
  int Solution::trap(const vector<int> &A) {
    int s=A.size();
    int l[s];
    l[0]=A[0];
    for(int i=1;i<s;i++)
    {
        l[i]=max(l[i-1],A[i]);
    }
    int r[s];
    r[s-1]=A[s-1];
    for(int i=s-2;i>=0;i--)
    {
        r[i]=max(r[i+1],A[i]);
    }
    int sum=0;
    for(int i=0;i<s;i++)
    {
        if(sum<0)
          sum=0;
        sum+=(min(l[i],r[i])-A[i]);
    }
    return sum;
  }
