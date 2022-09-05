#include <bits/stdc++.h>
using namespace std;

int main()
{
    int p;
    cin >> p;
    
    while (p--)
    {
        int k, n;
        cin >> k >> n;
        
        cout << k << " " << (n * (n + 1) / 2) + n << endl;
    }
    return 0;
}