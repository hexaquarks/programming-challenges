#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int s, t, n;
    cin >> s >> t >> n;
    
    int ds[n + 1], bs[n], cs[n];
    for (int i = 0; i < n + 1; ++i) cin >> ds[i];
    for (int i = 0; i < n; ++i) cin >> bs[i];
    for (int i = 0; i < n; ++i) cin >> cs[i];
    
    int totT = 0, waitTime = 0, i = 0;
    while (i < n)
    {
        totT += ds[i];
        waitTime += totT < cs[i] ? cs[i] - totT : totT % cs[i];
        totT += waitTime + bs[i];
        ++i;
    }
    totT += ds[i];
    cout << (totT + s <= t ? "yes" : "no") << endl;
    return 0;
}