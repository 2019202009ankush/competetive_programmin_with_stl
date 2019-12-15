/*Find reverse of bit stream
  Written By:Ankush Mitra
  Date:15.12.19 Time:17.26*/
  unsigned int reverse(unsigned int A) {
      unsigned int count=0;
      for(int i=31;i>=0;i--)
      {
          if((A>>i)&1) count=count+(pow(2,31-i));
      }
      return count;
  }
