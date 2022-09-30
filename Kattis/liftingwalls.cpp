#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#pragma GCC target("sse4")

constexpr char* SHIT = "Hi!";

int computeDistance(const pair<int, int>& p, const pair<int, int>& s)
{
    return abs(p.first - s.first) + abs(p.second - p.second);
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0); 
    
    int l, w, n, r;
    cin >> l >> w >> n >> r;
    vector<pair<int, int>> cranes;
    while (n--)
    {
        int x, y;
        cin >> x >> y;
        cranes.push_back(make_pair(x, y));
    }

    vector<pair<int, int>> walls{
        make_pair(-l >> 1, 0),
        make_pair(0, w >> 1),
        make_pair(l >> 1, 0), 
        make_pair(0, -w >> 1)
    };

    vector<vector<int>> goodWalls;
    goodWalls.reserve(n);
    int i = 0;
    for (constexpr pair<int, int>& p : cranes)
    {
        int j = 0;
        for (constexpr pair<int, int>& s : walls)
        {
            int dist = computeDistance(p, s); 
            if (dist <= r) goodWalls[i].push_back(j);
            ++j;
        }
        ++i;
    }

    return 0;
}

// each number formed by its first  digits is
//  evenly divisible by , for  from  to , where  
//  is the number of digits in the number