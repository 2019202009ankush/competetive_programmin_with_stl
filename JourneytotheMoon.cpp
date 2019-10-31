/*
 * Author : thesigmaguy
 * Date : 31/Oct/2019
 * Name : Journey to the Moon
 * Approach : Disjoint Set Union
 */

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the journeyToMoon function below.

int find_parent(vector<pair<int,int>>& parent, int ind)
{
    vector<int> child;
    while(ind!=parent[ind].first)
    {
        child.push_back(ind);
        ind=parent[ind].first;
    }
    for(auto i:child)
        parent[i].first=ind;
    return ind;
}

long long journeyToMoon(int n, vector<vector<int>> astronaut) {
    vector<pair<int, int>> parent;
    for(int i=0;i<n;i++)
    {
        parent.push_back(make_pair(i,1));
    }
    for(int i=0;i<astronaut.size();i++)
    {
        int p1 = find_parent(parent,astronaut[i][0]);
        int p2 = find_parent(parent,astronaut[i][1]);
        if(p1!=p2)
        {
            if(parent[p1].second >= parent[p2].second)
            {
                parent[p2].first = p1;
                parent[p1].second+=parent[p2].second;
            }
            else
            {
                parent[p1].first = p2;
                parent[p2].second += parent[p1].second;
            }
        }
    }
    //groups will have parent(ie parent[i].first) and i should be same
    vector<int> groups;
    for(int i=0;i<parent.size();i++)
    {
        if(parent[i].first ==i)
            groups.push_back(parent[i].second);
    }

    long long sum=0;

    //We need combinations so once used groups size elements to be removed

    for(int i=0;i<groups.size();i++)
    {
        sum+=(groups[i]*(long long)(n-groups[i]));
        n-=groups[i];
    }
    return sum;
}
/*
 * Default Code
 * It had result as int which will overflow for some cases so changed it to long long
 */
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string np_temp;
    getline(cin, np_temp);

    vector<string> np = split_string(np_temp);

    int n = stoi(np[0]);

    int p = stoi(np[1]);

    vector<vector<int>> astronaut(p);
    for (int i = 0; i < p; i++) {
        astronaut[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> astronaut[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    long long result = journeyToMoon(n, astronaut);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) 
{
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

