#include <bits/stdc++.h>
using namespace std;

#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
#define ll long long
#define f first
#define s second
#define endl "\n"

#pragma GCC optimize("O3")
#pragma GCC target("sse4")

int main()
{
    IOS;
    string s;
    getline(cin, s);
    vector<int> v(1000);
    int odd = 0;
    
    for (char c: s)
    {
        ++v[c - '0'];
    }
    for (int i = 0; i < 1000; ++i)
    {
        if (v[i] != 0 && v[i] % 2 != 0) ++odd;
    }
    if (odd > 1) 
    {
        cout << odd - 1 << endl;
    } else cout << 0;
    
    return 0;
}