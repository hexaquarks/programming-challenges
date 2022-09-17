#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#pragma GCC target("sse4")

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;

    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c; // floor numbers

        int timeA = abs(a - 1);
        int timeB = abs(b - c) + abs(c - 1);

        if (timeA == timeB) cout << 3;
        else if (timeA < timeB) cout << 1;
        else if (timeA > timeB) cout << 2;
        cout << endl;
    }
    return 0;
}
