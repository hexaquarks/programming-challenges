#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int x, y, n, i = 1;
    cin >> x >> y >> n;
    
    while (n--)
    {
        if (i % x == 0 && i % y == 0) cout << "FizzBuzz";
        else if (i % y == 0) cout << "Buzz";
        else if (i % x == 0) cout << "Fizz";
        else cout << i;
        cout << endl;
        ++i;
    }
    return 0;
}