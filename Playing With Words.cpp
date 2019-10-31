#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>
#include <iostream>
#include <climits>
using namespace std;

int difference(string str1, string str2)
{
    int count =0;
    int i=0;
    while(i<str1.length())
    {
        if(str1[i] == str2[i])
            count++;
        i++;
    }
    return str1.length()-count;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string beginword;
    string endword;
    
    cin>>beginword>>endword;
    
    if(beginword.length()!=endword.length())
    {
        cout<<0<<endl;
        return 0;
    }
    
    int n;
    cin>>n;
    
    unordered_set<string> words;
    
    queue<string> word_queue;
    
    unordered_map<string,bool> visited;
    
    unordered_map<string, int> distance;
    distance[beginword]=0;

    for(int i=0;i<n;i++)
    {
        string word;
        cin>>word;
        if(word.length() == beginword.length())
        {
            words.insert(word);
            visited[word] = false;
            distance[word] =INT_MAX;
            int val=difference(beginword, word);
            if(val==1)
            {
                word_queue.push(word);
                visited[word]=true;
                distance[word]=2;
            }
        }
    }
    
    
    if(words.find(endword)!=words.end())
    {

        while(!word_queue.empty())
        {
            string front = word_queue.front();
            word_queue.pop();
            words.erase(front);
            for(unordered_set<string>::iterator i = words.begin(); i!=words.end(); i++)
            {
                if(!visited[*i] && difference(front, *i)==1)
                {
                    visited[*i]=true;
                    distance[*i]=distance[front]+1;
                    word_queue.push(*i);
                }
            }
        }
        cout<<distance[endword]<<endl;
        
    }
    else
    {
        cout<<0<<endl;
        return 0;
    }
    
    
    return 0;
}

