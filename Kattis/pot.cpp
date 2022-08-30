#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    int ans = 0;
    
    while (n--)
    {
        int pi;
        cin >> pi;
        
        ans += pow(floor(pi / 10), pi % 10);
    }
    cout << ans << endl;
    return 0;
}