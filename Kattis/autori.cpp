#include <bits/stdc++.h>
using namespace std;

int main()
{
    string name, ans;
    getline(cin, name);
    
    ans += name[0];
    vector<int> idx;
    int i = 0;
    
    while (i < name.size())
    {
        if (name[i] == '-') ans += name[i + 1];
        ++i;
    }
    cout << ans;
    return 0;
}