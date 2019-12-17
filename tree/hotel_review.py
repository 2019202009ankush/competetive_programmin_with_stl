/* Hotel review in pyhton
   Written By:Ankush Mitra
   Date:16.12.19 Time:2.25*/
   class Solution:
       # @param A : string
       # @param B : list of strings
       # @return a list of integers
       def solve(self, A, B):
           good_word=A.split('_')
           lis=[]
           i=0
           for word in B:
               count=0

               for sp in word.split('_'):
                   if sp in good_word:
                       count+=1
               lis.append([i,count])
               i+=1
           lis.sort(key=lambda x:x[1],reverse=True)
           return [x[0] for x in lis]
