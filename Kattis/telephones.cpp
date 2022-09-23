#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#pragma GCC target("sse4")

bool isOverlapping(int x1,int x2,int y1,int y2)
{
    int overlap = min(x2, y2) - max(x1, y1);
    return max(x1,y1) <= min(x2,y2) && overlap >= 1;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0); 
    int n, m;
    while (cin >> n >> m)
    {
        if (!n && !m) break;
        vector<pair<int, int>> calls, interests;
        while (n--)
        {
            int so, de, st, du;
            cin >> so >> de >> st >> du;
            
            calls.push_back(make_pair(st, du));
        }
        while (m--)
        {
            int st, du;
            cin >> st >> du;
            interests.push_back(make_pair(st, du));
        }
        
        for (const pair<int, int>& p : interests)
        {
            int ans = 0;
            for (const pair<int, int>& c : calls)
            {
                if (isOverlapping(c.first, c.first + c.second, 
                                  p.first, p.first + p.second)) 
                    ++ans;
            }
            cout << ans <<endl;
        }
    }
    
    return 0;
}