#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int g, t, n;
    cin >> g >> t >> n;
    
    int tot = 0, perc = g - t, temp;
    while (n--)
    {
        cin >> temp;
        tot += temp;
    }
    cout << 0.9 * perc - tot << endl; 
    return 0;
}