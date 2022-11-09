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
        
        int totDeg = 0;
        pair<double, double> pos(0, 0);
        
        while (m--)
        {
            string command;
            cin >> command;
            int val;
            cin >> val;
            
            if (command == "fd") {
                double rad = totDeg * (PI / 180);
                pos.f += val * sin(rad);
                pos.s += val * cos(rad);
            } else if (command == "lt") {
                totDeg += val;
            } else if (command == "rt") {
                totDeg -= val;
            } else if (command == "bk") {
                double rad = totDeg * (PI / 180);
                pos.f -= val * sin(rad);
                pos.s -= val * cos(rad);
            }
            totDeg %= (totDeg < 0) ? -360 : 360;
        }
        
        double dist = sqrt(
            pow((pos.f), 2) + pow((pos.s), 2)
        );
        int ans = round(dist);
        cout << ans << endl;
    }
    return 0;
}