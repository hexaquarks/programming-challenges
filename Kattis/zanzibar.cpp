#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    
    while (t--)
    {
        int prev = 1, tot = 0;
        while (true)
        {
            int val;
            cin >> val;
            if (!val) break;
            if (val > 2 * prev) tot += val - 2 * prev;
            prev = val;
        }
        cout << tot << endl;
    }
    return 0;
}
