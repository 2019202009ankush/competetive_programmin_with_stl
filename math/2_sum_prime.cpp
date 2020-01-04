/* 2 sum prime
  Written By:ANkush Mitra
  Date:4.1.20 Time:15:45*/
  vector<int> Solution::primesum(int N) {
    vector<bool>seive(N+1,true);
    seive[0]=0;
    seive[1]=0;
    for(int i=2;i*i<=N;i++)
    {
        if(seive[i])
        {
            for(int j=2*i;j<=N;j+=i)
            {
                seive[j]=0;
            }
        }
    }
    for(int i=2;i<=N;i++)
    {
        if(seive[i]&&seive[N-i])
          return {i,N-i};
    }
    return {};
  }
