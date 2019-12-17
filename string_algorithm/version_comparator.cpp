/* Checking Version
   Written By:ANkush Mitra
   Date:17.12.19 Time:20.21*/
   int Solution::compareVersion(string A, string B) {
     stringstream ss(A);
     stringstream ss1(B);
     string w1;
     string w2;
     while(getline(ss,w1,'.')&&getline(ss1,w2,'.'))
     {
         // cout<<w1<<" "<<w2<<endl;
        if(w1.length()>17 || w2.length()>17) return w1.length()<w2.length()?-1:1;
        else
            {if(stoull(w1.c_str())<stoull(w2.c_str())) {return -1;break ; }
            else if(stoull(w1.c_str())>stoull(w2.c_str())){ return 1; break; }}

     }
     if(getline(ss,w1,'.'))
     {
      return 1;
     }
     else if(getline(ss1,w2,'.'))
     {
       return -1;
     }
     else
       return 0;
 }
