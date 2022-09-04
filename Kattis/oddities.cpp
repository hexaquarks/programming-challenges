#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    
    while (n--)
    {
        int x;
        cin >> x;
        
        cout << x << " is " << string((x % 2 == 0) ? "even" : "odd") << endl;
    }
    return 0;
}