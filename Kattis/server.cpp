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
    int n, t;
    cin >> n >> t;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    int tot = 0, ans =0;
    for (int i : v)
    {
        if (tot + i > t) break;
        tot += i;
        ++ans;
    }
    cout << ans;
    return 0;
}