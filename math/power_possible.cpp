/* Find if a number can be represented as in power of some number
  Written By:Ankush Mitra
  Date:4.1.20 Time:20.20*/
  int Solution::isPower(int A) {
      if(A==1) return 1;
    for(int i=1;i<=sqrt(A);i++)
    {
        if(float(log(A)/log(i))==int((log(A)/log(i))))
          return 1;
    }
    return 0;
  }
