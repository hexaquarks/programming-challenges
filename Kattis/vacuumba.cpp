#include <bits/stdc++.h>
using namespace std;

#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
#define ll long long
#define PI 3.14159265358979323846
#define f first
#define s second
#define endl "\n"

#pragma GCC optimize("O3")
#pragma GCC target("sse4")

int main()
{
    IOS;
    int n;
    cin >> n;
    while (n--)
    {
        int m;
        cin >> m;
        double tot = 90;
        pair<double, double> pos(0, 0);
        for (int i = 0; i < m; ++i)
        {
            double a, b;
            cin >> a >> b;
            tot += a;
            tot = fmod(tot, (tot < 0) ? -360 : 360);
            double rad = tot * (double) (PI / 180);
            double newY = b * sin(rad);
            double newX = b * cos(rad);
            pos.f += newX;
            pos.s += newY;
        }
        cout << fixed << setprecision(6) << pos.f << " ";
        cout << fixed << setprecision(6) << pos.s << endl;
    }
    return 0;
}