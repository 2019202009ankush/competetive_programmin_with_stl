/*Count the number of 1 in a bit stream
  Written By: Ankush Mitra
  Date:15,12,19 Time:17,20*/
  int numSetBits(unsigned int A) {
  
    int count=0;
    for(int i=31;i>=0;i--)
    {
        if((A>>i)&1) count++;
    }
    return count;
}
