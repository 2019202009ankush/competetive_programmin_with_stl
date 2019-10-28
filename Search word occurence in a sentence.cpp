/* Search word occurence in a sentence
   written by : Ankush Mitra
   Date : 28.10.19 Time: 23.57 */
#include<bits/stdc++.h>
using namespace std;
map<string,int>wordCount;
int main()
{
   string s;
   getline(cin,s,'\n');
   string word;
    cin>>word;
    transform(s.begin(),s.end(),s.begin(),::tolower);
    transform(word.begin(),word.end(),word.begin(),::tolower);
    if(word=="")
    {
        cout<<"0"<<endl;
        return 0;
    }
    stringstream ss(s);
    string temp;
    while(getline(ss,temp,' '))
    {
        //cout<<temp<<endl;
        if(temp!=" ")
        wordCount[temp]++;
    }
    cout<<wordCount[word]<<endl;
}
