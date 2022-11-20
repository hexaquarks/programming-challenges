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

const vector<pair<int, int>> deltas = {
    {-2, -1}, {-1, -2}, 
    {1, -2}, {2, -1}, 
    {2, 1}, {1, 2}, 
    {-1, 2}, {-2, 1}
};

bool isValid(int nx, int ny, const vector<vector<char>>& m) 
{
    return (nx >= 0 && nx < m.size() && ny >= 0 && ny < m.size() && m[nx][ny] != '#');
}

bool bfs(
    vector<vector<char>>& m,
    vector<vector<int>>& mem,
    queue<pair<int, pair<int, int>>>& q) 
{
    while (!q.empty())
    {
        auto [steps, pos] = q.front();
        q.pop();
        
        for (int i = 0; i < 8; ++i)
        {
            auto [dx, dy] = deltas[i];
            int nx = pos.f + dx;
            int ny = pos.s + dy;
            
            if (!isValid(nx, ny, m) || steps >= mem[nx][ny]) continue;
            if (!nx && !ny) 
            {
                cout << steps;
                return true;
            }
            q.push(make_pair(steps + 1, make_pair(nx, ny)));
            mem[nx][ny] = steps;
        }
    }
    return false;
}

int main()
{
    IOS;
    int n;
    cin >> n;
    vector<vector<char>> m(n, vector<char>(n));
    pair<int, int> knight;
    
    cin.ignore();
    cin.clear();
    
    for (int i = 0; i < n; ++i)
    {
        string s;
        getline(cin, s);
        for (int j = 0; j < n; ++j)
        {
            m[i][j] = s[j];
            if (m[i][j] == 'K') knight = {i, j};
        }
    }
    
    vector<vector<int>> mem(m.size(), vector<int>(m.size()));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (m[i][j] == '#') mem[i][j] = -1;
            else if (m[i][j] == 'K') 
            {
                if (!i && !j) { cout << 0; return 0; }
                mem[i][j] = 0;
            }
            else mem[i][j] = 1000;
        }
    }
    
    queue<pair<int, pair<int, int>>> q;
    q.push(make_pair(1, knight));
    
    if (!bfs(m, mem, q)) cout << -1;
    return 0;
}