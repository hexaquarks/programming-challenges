#include <bits/stdc++.h>
using namespace std;

#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
#define ll long long
#define f first
#define s second
#define endl "\n"

#pragma GCC optimize("O3")
#pragma GCC target("sse4")

int main()
{
    IOS;
    ll n, t;
    cin >> n >> t;
    
    ll a, b, c, t0;
    cin >> a >> b >> c >> t0;
    
    vector<ll> v{t0};
    for (int i = 1; i < n; ++i)
    {
        ll ti = ((a * v[i - 1] + b) % c) + 1;
        v.push_back(ti);
    }
    sort(v.begin(), v.end());
    ll totPen = 0, totTime = 0;
    int i = 0;
    while (i < v.size())
    {
        ll problem = v[i];
        if (totTime + problem > t) break;

        totTime += problem;
        totPen += totTime;
        ++i;
    }
    cout << i << " " << (totPen % 1000000007);
    
    return 0;
}