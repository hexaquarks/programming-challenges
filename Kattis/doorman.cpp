#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int x;
    cin >> x; 
    
    string s;
    cin >> s;
    
    int counter = s[0] == 'W' ? 1 : -1, i = 1;
    char prev = s[0];

    for (; i < s.size(); ++i)
    {
        char c = s[i];
        if ((counter == x || counter  == -x) && c == prev) 
        {
            if (i + 1 < s.size() && s[i + 1] != c) 
            {
                swap(s[i] , s[i + 1]);
                c == 'W' ? --counter : ++counter;
            }
            else break;
        } else c == 'W' ? ++counter : --counter;
        prev = c;
    }
    cout << i;
    return 0;
}