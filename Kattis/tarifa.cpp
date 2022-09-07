#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int x, n, tot = 0;
    cin >> x >> n;
    
    while (n--)
    {
        int p;
        cin >> p;
        tot += x - p;   
    }
    cout << (tot + x);
    return 0;
}