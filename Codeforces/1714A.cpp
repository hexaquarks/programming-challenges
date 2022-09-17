#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#pragma GCC target("sse4")

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0); 
    
    int t;
    cin >> t;
    while (t--)
    {
        int n, H, m;
        cin >> n >> H >> m;
        vector<pair<int, int>> alarms;
        pair<int, int> ans;
        while (n--)
        {
            int hi, mi;
            cin >> hi >> mi;

            int diffH = hi - Hi, diffM = mi - m;
            if (diffH < 0) { timeH += 24; }
            if (diffM < 0) { --timeH; timeM += 60; }
            
            if (timeH < ans.first) ans = make_pair(diffH, diffM);
            else if (timeH == ans.first && timeM < ans.second)
            {
                ans.second = diffM;
            }
        }
        cout << ans.first << " " << ans.second << "\n";
    }
    return 0;
}