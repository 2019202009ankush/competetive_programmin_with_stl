/* Find   number of subsstring of all vowel
  Written By:ANkush Mitra
  Date:5.1.20 Time:21.25*/
  #include <bits/stdc++.h>
  using namespace std;
  bool isVowel(char s)
  {
   return s=='a'||s=='e'||s=='i'||s=='o'||s=='u';
  }
  int count_vowel(string t)
  {
    int n=t.size();
    int count=0;
    int start=0;
    unordered_map<char,int> m;
    for(int i=0;i<t.size();i++)
    {
       m[t[i]]++;
      while(m['a']>0&&m['e']>0&&m['i']>0&&m['o']>0&&m['u']>0)
      {
         count+=(n-i);
         m[t[start]]--;
        start++;
      }
    }
   return count;
  }
  int countSubstrings(string s)
  {
    if(s.size()<=4) return 0;
    string temp="";
    int count=0;
    for(int i=0;i<s.size();i++)
    {
     if(isVowel(s[i]))
        temp+=s[i];
     else
        {
          if(temp.size()>4){
           int tempCount=count_vowel(temp);
           count+=tempCount;
          }
          temp="";
        }
    }
        if(temp.size()>=4)
        {
          int tempCount=count_vowel(temp);
          count+=tempCount;
        }
        temp="";
      return count;
        }
