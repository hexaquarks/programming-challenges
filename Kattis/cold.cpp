#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, ans = 0;
    cin >> n;
    
    while (n--)
    {
        int t;
        cin >> t;
        if (t < 0) ++ans;
    }
    cout << ans;
    return 0;
}