/* Integer to ROmman
   Written By:ANkush Mitra
   Date:17.12.19 Time:23.38*/
   string Solution::intToRoman(int A) {
       string arr[]={"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
       int val[]={1,4,5,9,10,40,50,90,100,400,500,900,1000};
       int i=12;
       string w;
       while(A>0&i>=0)
       {
           int num=A/val[i];
            A=A%val[i];
           while(num--)
           {
               w.append(arr[i]);
           }
           i--;
       }
       return w;
   }
