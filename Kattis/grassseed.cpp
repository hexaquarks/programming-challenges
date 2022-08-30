#include <bits/stdc++.h>
using namespace std;

int main()
{
    double c, ans = 0.0;
    int l;
    cin >> c >> l;
    
    while (l--)
    {
        double wi, li;
        cin >> wi >> li;
        ans += wi * li * c;
    }
    
    cout << fixed << setprecision(7) << ans << endl;
    return 0;
}