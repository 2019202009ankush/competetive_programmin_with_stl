/* Find x such that A%x==0 (factor of A) and __gcd(x,B) ==1
  Writteen By:Ankush Mitra
  Date:4.1.12 Time:23.43*/
  int Solution::cpFact(int A, int B) {
      while(__gcd(A,B)!=1)
      {
          A=A/__gcd(A,B);
      }
      return A;
  }
