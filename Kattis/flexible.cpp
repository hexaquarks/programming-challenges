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

int get_sum(vector<int>& v, int i, int j)
{
    int tot = 0;
    int prev = i;
    for (int k = prev + 1; k <= j; ++k)
    {
        tot += v[k] - v[prev];
        prev = k;
    }
    return tot;
}

int main()
{
    IOS;
    int w, n;
    cin >> w >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i];
    
    set<int> s;
    // first pass
    int prev = 0;
    for (int i = 1; i < n; ++i)
    {
        int diff = p[i] - prev;
        prev = p[i];
        s.insert(diff);
    }
    
    // second pass
    int tot = 0;
    vector<int> pp;
    pp.push_back(0);
    for (int i : p) pp.push_back(i);
    pp.push_back(w);
    
    for (int i = 0; i < n + 2; ++i)
    {
        for (int j = i + 1; j < n + 2; ++j)
        {
            tot = get_sum(pp, i, j);
            if (tot <= w && tot > 0) s.insert(tot);
        }
    }
    
    for (const int i : s)
    {
        cout << i << " ";
    }
    return 0;
}