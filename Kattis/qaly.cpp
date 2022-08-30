#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    double ans = 0.0;
    
    while (n--)
    {
        double q, y;
        cin >> q >> y;
        ans += q * y;
    }
    
    cout << fixed << setprecision(3) << ans << endl;
    return 0;
}
