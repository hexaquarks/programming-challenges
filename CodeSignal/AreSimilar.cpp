#include <bits/stdc++.h>
using namespace std;

bool solution(vector<int> a, vector<int> b) 
{
    if (string(a.begin(), a.end()) == string(b.begin(), b.end())) return true;
    vector<int> v1, v2;
    for (int i = 0; i < b.size(); ++i)
    {
        if (b[i] != a[i]) 
        {
            v1.push_back(a[i]);
            v2.push_back(b[i]);
        }
    }
    reverse(v2.begin(), v2.end());
    if (v2.size() == 2 && (string(v1.begin(), v1.end()) == string(v2.begin(), v2.end()))) return true;
    return false;
}


/* Alternatively */
bool solution(vector<int> a, vector<int> b) 
{
    set<int> mem1, mem2;
    int count = 0;
    
    for (const int val : a) mem1.insert(val);
    for (int i = 0; i < b.size(); ++i)
    {
        if (b[i] != a[i]) ++count;
        if (count > 2) return false;
        mem2.insert(b[i]);
    }
    return (mem1 == mem2 && (count == 0 || count == 2));
}