#include <bits/stdc++.h>
using namespace std;

void DFS(vector<vector<bool>>& visited, int i, int j)         
{
    visited[i][j] = true;
    if (i - 1 >= 0 && !visited[i - 1][j]) DFS(visited, i - 1, j);
    if (i + 1 < visited.size() && !visited[i + 1][j]) DFS(visited, i + 1, j);
    if (j - 1 >= 0 && !visited[i][j - 1]) DFS(visited, i, j - 1);
    if (j + 1 < visited[0].size() && !visited[i][j + 1]) DFS(visited, i, j + 1);
}

int main()
{
    ios::sync_with_stdio(false);
    int testCase = 1;
    
    int m, n;
    while (cin >> m && cin >> n)
    {
        int counter = 0;
        vector<vector<bool>> visited(m, vector<bool>(n));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j) 
            {
                char c;
                cin >> c;
                visited[i][j] = (c == '#');
            }
        }
        
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (!visited[i][j])
                {
                    DFS(visited, i, j);
                    ++counter;
                }
            }
        }
        
        cout << "Case " << testCase << ": " << counter << endl;
        ++testCase;
    }
    return 0;
}