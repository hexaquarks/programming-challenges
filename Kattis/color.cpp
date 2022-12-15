#include <bits/stdc++.h>
using namespace std;

#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0)
#define ll long long
#define f first
#define s second

#pragma GCC optimize("O3")
#pragma GCC target("sse4")

int main()
{
    IOS;   
    ll s, c, k;
    cin >> s >> c >> k;
    vector<ll> d(s);
    for (int i = 0; i < s; ++i) cin >> d[i];
    
    sort(d.begin(), d.end());
    ll counter = 1, prev = d[0], machines = 1;
    
    for (size_t i = 1; i < s; ++i)
    {
        if (counter >= c || !(abs(d[i] - prev) <= k)) 
        {
            prev = d[i];
            counter = 1;
            ++machines;
        }
        else ++counter;
    }
    
    cout << machines;
    
    return 0;
}