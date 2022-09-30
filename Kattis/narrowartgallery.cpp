#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#pragma GCC target("sse4")

enum class Choice
{
    LEFT, 
    RIGHT,
    NONE
};

map<tuple<int, int, Choice>, int> mem;

int rec(vector<pair<int, int>>& grid, int n, int k, Choice c)
{
    if (n == -1) {
        if (k == 0)  return 0;
        else return numeric_limits<int>::min(); 
    }
    
    if (mem.find({n, k, c}) != mem.end()) return mem[{n, k, c}];
    
    pair<int, int> row = grid[n];
    int maxEl;
    
    if (c == Choice::NONE)
    {
        vector<int> paths{
            rec(grid, n - 1, k, Choice::NONE) + row.first + row.second, 
            rec(grid, n - 1, k - 1, Choice::LEFT) + row.second, 
            rec(grid, n - 1, k - 1, Choice::RIGHT) + row.first
        };
        maxEl = *max_element(paths.begin(), paths.end());
    }
    else if (c == Choice::LEFT)
    {
        maxEl = max(
            rec(grid, n - 1, k - 1, Choice::LEFT) + row.second, 
            rec(grid, n - 1, k, Choice::NONE) + row.first + row.second
        );
    }
    else if (c == Choice::RIGHT)
    {
        maxEl = max(
            rec(grid, n - 1, k - 1, Choice::RIGHT) + row.first, 
            rec(grid, n - 1, k, Choice::NONE) + row.first + row.second
        );
    }
    
    mem[{n, k, c}] = maxEl;
    return maxEl;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0); 
    
    int n, k, i = 0;
    cin >> n >> k;
    
    vector<pair<int, int>> grid;
    for(int i = 0; i <= n; ++i)
    {
        int val1, val2;
        cin >> val1; 
        cin >> val2;
        if (i != n) grid.push_back(make_pair(val1, val2));
    }

    pair<int, int> row = grid[n - 1];
    vector<int> paths{
        rec(grid, n - 2, k, Choice::NONE) + row.first + row.second,
        rec(grid, n - 2, k - 1, Choice::LEFT) + row.second,
        rec(grid, n - 2, k - 1, Choice::RIGHT) + row.first
    };
        
    cout << *max_element(paths.begin(), paths.end()) << endl;
    
    return 0;
}