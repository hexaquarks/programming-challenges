#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    
    int i = 1, ans = 0;
    while (true)
    {
        n -= (i * i); 
        if (n >= 0) { i += 2; ++ans; }
        else break;
    }
    cout << ans;
    return 0;
}