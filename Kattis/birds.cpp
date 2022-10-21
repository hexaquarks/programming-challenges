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

int getBirdsAvailable(int dist, int d)
{
    if (dist <= 0) return 0;
    return dist / d + 1;
}

int main()
{
    IOS;
    int l, d, n;
    cin >> l >> d >> n;
    
    vector<int> pos(n);
    for (int i = 0; i < n; ++i) cin >> pos[i];
    sort(pos.begin(), pos.end());
    
    // edge cases
    if (!n) 
    {
        cout << getBirdsAvailable(l - 12, d) << endl;
        return 0;
    }
    int curr = 6;
    int ans = 0;
    
    for (int i = 0; i < n; ++i)
    {
        int dist = pos[i] - curr;
        int num = dist / d;
        ans += num;
        curr = pos[i] + d;
    }
    int dist = getBirdsAvailable(l - 6 - curr, d);
    ans += dist;
    
    cout << ans << endl;
    return 0;
}