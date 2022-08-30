#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    int ans = 0;
    
    while (n--)
    {
        int l;
        cin >> l;
        ans += l - 1;
    }
    cout << ++ans << endl;
    return 0;
}